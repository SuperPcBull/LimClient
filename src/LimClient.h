/*
 * ProxyClient.h
 *
 *  Created on: 2017年6月14日
 *      Author: xzl
 */

#ifndef PROXY_PROXYCLIENT_H_
#define PROXY_PROXYCLIENT_H_

#include <memory>
#include "jsoncpp/json.h"
#include "Network/TcpClient.h"
#include "LimProtocol.h"
#include "Util/SSLBox.h"
#include "Util/onceToken.h"

using namespace Json;
using namespace toolkit;

namespace Lim {


typedef function<void(int code,const string &msg)> onEvent;
typedef function<void(const Value &obj,const string &body)> onPush;


class LimClient: public TcpClient , public LimProtocol {
public:
	typedef std::shared_ptr<LimClient> Ptr;

	LimClient();
	virtual ~LimClient();

	/**
	 * 登录lim服务器
	 * @param url 服务器ip或域名
	 * @param port 服务器端口号
	 * @param uid 用户唯一id
	 * @param pwd 用户密码
	 * @param userInfo 用户其他附带信息
	 */
	void login(const string &url,uint16_t port,const string &uid,const string& pwd,const Value &userInfo);

	/**
	 * 登出
	 */
	void logout();

	/**
	 * 获取登录状态
	 * @see STATUS_CODE
	 * @return 登录状态
	 */
	int status() const;

	/**
	 * 设置登录结果回调
	 * @param onLogin
	 */
    void setOnLogin(const onEvent& onLogin);

	/**
	 * 设置掉线事件回调
	 * @param onShutdown
	 */
	void setOnShutdown(const onEvent& onShutdown);

	/**
	 * 设置收到推送事件回调
	 * @param onPush
	 */
	void setOnPush(const onPush& onPush);
protected:
	//// TcpClient override ////
	void onConnect(const SockException &ex) override;
	void onRecv(const Buffer::Ptr &pBuf) override;
	void onErr(const SockException &ex) override;
	//// LimProtocol override ////
	bool onProcessRequest(const string &cmd,uint64_t seq,const Value &obj,const string &body) override;
	int  onSendData(const string &data) override;
private:
	//// cmd callback ////
	void handleRequest_conflict(uint64_t seq, const Value &obj,const string &body);
	void handleRequest_push(uint64_t seq, const Value& obj,const string& body);
private:
	void disconnect(int code,const string &msg);
	void sendRequest_login();
	void sendBeat();
	void onManager() override ;
private:
	string _uid;
	string _pwd;
	Value _userInfo;
	onEvent _onLogin;
	onEvent _onShutdown;
	onPush _onPush;
	STATUS_CODE _status = STATUS_LOGOUTED;

};




} /* namespace Lim */

#endif /* PROXY_PROXYCLIENT_H_ */
