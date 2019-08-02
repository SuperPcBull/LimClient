/*
 * ProxyProtocol.cpp
 *
 *  Created on: 2017年6月14日
 *      Author: xzl
 */


#include "Util/onceToken.h"
#include "Network/sockutil.h"
#include "LimProtocol.h"
using namespace toolkit;

#define BODY_LEN "body_len"


namespace Lim {

LimProtocol::LimProtocol(SubClassType type){
	_subclass = type;
	_reqSeq = ((uint64_t)this) % 10000;
}

LimProtocol::~LimProtocol() {
	manageResponse(CODE_OTHER,"disconnect from server",true);
}

int64_t LimProtocol::onRecvHeader(const char *data, uint64_t len) {
    stringstream ss(string(data,len - 4));
    ss >> _header;
    auto body_len = _header[BODY_LEN].asUInt64();
    if(body_len == 0){
		handlePacket(_header,"");
	}
	return body_len;
}

void LimProtocol::onRecvContent(const char *data, uint64_t len) {
	handlePacket(_header,string(data,len));
}

void LimProtocol::onRecvData(const char *data,uint64_t size) {
	GET_CONFIG(float,sec,Config::Lim::kResTimeoutSec);
	if(_recvTicker.elapsedTime() > sec * 1000){
		if(HttpRequestSplitter::reset()){
		    WarnL << "丢弃过期残余包数据!";
		}
	}
	_recvTicker.resetTime();
    input(data,size);
}

void LimProtocol::manageResponse(int code, const string& msg,bool flushAll) {
	//管理回调，超时就执行并移除
	decltype(_mapResponse) copy;
	copy.swap(_mapResponse);

	for(auto it = copy.begin() ; it != copy.end() ;){
		if(it->second->expired() || flushAll){
			(*(it->second))(code,msg,Json::objectValue,"");
			it = copy.erase(it);
			continue;
		}
		++it;
	}

	//没有剩余的回复回调
	if(copy.empty()){
		return;
	}

	//在遍历回复回调时，未新增新的回复回调
	if(_mapResponse.empty()){
		copy.swap(_mapResponse);
		return;
	}

	//在遍历回复回调时，新增了新的回复回调
	_mapResponse.insert(copy.begin(),copy.end());
}

/*
 *
 * onRecv ----> handlePacket --------> handleRequest
 * 							|
 * 							|-------> handleResponse
 */
void LimProtocol::handlePacket(const Value& header, const string& body) {
	auto type = header["type"].asString();
	typedef void (LimProtocol::*onHandlePacket)(const Value &header,const string &body);
	static unordered_map<string,onHandlePacket> map_type_fun;
	static onceToken token([&](){
		map_type_fun.emplace("request",&LimProtocol::handleRequest);
		map_type_fun.emplace("response",&LimProtocol::handleResponse);
	},nullptr);

	auto it = map_type_fun.find(type);
	if(it == map_type_fun.end()){
		//不会有其他类型，这里断开连接
		auto strErr = StrPrinter << "LimProtocol::handlePacket 不支持的命令类型:" << type << endl;
		throw std::invalid_argument(strErr);
	}
	auto fun = it->second;
	(this->*fun)(header,body);
}


/*
 *
 *  handleRequest --------> handleRequest_login
 * 					 |
 * 					 |----> handleRequest_transfer
 */
void LimProtocol::handleRequest(const Value& header, const string& body) {
	/*
	 * 请求类型的头：
	 * {
	 *   "type":"request",		// 请求类型
	 *	 "seq":0,  				// 请求序号
	 *	 "cmd":"transfer",		// 命令名称
	 *	 "obj":{}				// 请求对象
	 * }
	 */
	auto seq 	= header["seq"].asUInt64();
	auto cmd 	= header["cmd"].asString();
	auto &obj	= header["obj"];
	if(!onProcessRequest(cmd,seq,obj,body)){
	    throw std::runtime_error(string("onProcessRequest failed:") + cmd);
	}
}

//收到回复信令；找到回复信令匹配的回调并执行
void LimProtocol::handleResponse(const Value& header, const string& body) {
	/*
	 * 回复类型的头：
	 * {
	 * 	"type":"response",      // 回复类型
	 * 	"seq": 0,			    // 回复序号（对应请求序号）
	 * 	"code":0,				// 回复代码（0:成功，其他：错误）
	 * 	"msg":"success",        // 回复文本（一些错误提示）
	 * 	"obj":{}					// 回复对象
	 * }
	 */
	auto seq 	= header["seq"].asUInt64();
	auto code 	= header["code"].asInt();
	auto msg	= header["msg"].asString();
	auto &obj	= header["obj"];
	auto it 	= _mapResponse.find(seq);
	if(it == _mapResponse.end()){
		WarnL << this << " " << "未找到匹配的回调:" << seq << " " << _subclass ;
		return;
	}
	ResponseBinder::Ptr cb = it->second;
	_mapResponse.erase(it);
	(*cb)(code,msg,obj,body);
}

void LimProtocol::sendRequest(const string& cmd, const Value& obj, const string& body,const onResponse &cb) {
	/*
	 * 请求类型的头：
	 * {
	 *   "type":"request",		// 请求类型
	 *	 "seq":0,  				// 请求序号
	 *	 "cmd":"transfer",		// 命令名称
	 *	 "obj":{}				// 请求对象
	 * }
	 */
	Value header(objectValue);
	header["type"] = "request";
	header["seq"] = (UInt64)_reqSeq;
	header["cmd"] = cmd;
	header["obj"] = obj;
	if(cb){
		_mapResponse[_reqSeq] = std::make_shared<ResponseBinder>(cb);
	}
    sendPacket(header,body);
	_reqSeq++;
}
void LimProtocol::sendResponse(uint64_t seq, int code, const string& msg,const Value& obj, const string& body) {
	/*
	 * 回复类型的头：
	 * {
	 * 	"type":"response",      // 回复类型
	 * 	"seq": 0,			    // 回复序号（对应请求序号）
	 * 	"code":0,				// 回复代码（0:成功，其他：错误）
	 * 	"msg":"success",        // 回复文本（一些错误提示）
	 * 	"obj":{}					// 回复对象
	 * }
	 */
	Value header(objectValue);
	header["type"] = "response";
	header["seq"] = (UInt64)seq;
	header["code"] = code;
	header["msg"] = msg;
	header["obj"] = obj;
	//DebugL << seq;
	sendPacket(header,body);
}

void LimProtocol::sendPacket(const Value &header, const string &body) {
	_sendTicker.resetTime();
	const_cast<Value&>(header)[BODY_LEN] = (UInt64)body.length();
	FastWriter writer;
	onSendData(writer.write(header) + "\r\n\r\n" + body);
}


} /* namespace Lim */
