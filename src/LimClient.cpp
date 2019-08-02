#include "LimClient.h"
#include "Config.h"
#include "Network/sockutil.h"
#include "Util/onceToken.h"
#include "Util/NoticeCenter.h"
using namespace toolkit;

namespace Lim {

class ConflictException : public std::exception {
public:
    ConflictException(const string &ip, const Value &obj) : _ip(ip), _obj(obj) {}
    virtual ~ConflictException() {}
    const char *what() const noexcept override { return _ip.data(); }
    const Value &getObj() const { return _obj; }
private:
    string _ip;
    Value _obj;
};

//////////////////////////////////////////////////////////////////

LimClient::LimClient() : TcpClient(EventPoller::Instance().shared_from_this()),LimProtocol(TYPE_CLIENT) {}

LimClient::~LimClient() {
    DebugL << "uid:" << _uid;
}

int LimClient::status() const {
    return (int) _status;
}

void LimClient::setOnLogin(const onEvent &onLogin) {
    _onLogin = onLogin;
}

void LimClient::setOnShutdown(const onEvent &onShutdown) {
    _onShutdown = onShutdown;
}
void LimClient::setOnPush(const onPush& onPush){
    _onPush = onPush;
};

void LimClient::login(const string &url,
                      uint16_t port,
                      const string &uid,
                      const string &pwd,
                      const Value &userInfo) {
    if (_status != STATUS_LOGOUTED) {
        if (_onLogin) {
            _onLogin(CODE_OTHER, "logined or logining");
        }
        return;
    }
    _uid = uid;
    _pwd = pwd;
    _userInfo = userInfo;
    _status = STATUS_LOGINING;
    GET_CONFIG(float, sec, Config::Lim::kResTimeoutSec);
    startConnect(url, port, sec);
}

void LimClient::logout() {
    if (_status == STATUS_LOGOUTED) {
        //尚未登录
        return;
    }
    disconnect(CODE_SUCCESS, "logout");
}

void LimClient::disconnect(int code, const string &msg) {
    HttpRequestSplitter::reset();
    shutdown(SockException((ErrCode)code,msg));
    manageResponse(CODE_OTHER, msg, true);
    _status = STATUS_LOGOUTED;
}

void LimClient::onConnect(const SockException &ex) {
    if (!ex) {
        //连接成功
        sendRequest_login();
        return;
    }
    //连接失败
    _status = STATUS_LOGOUTED;
    if (_onLogin) {
        _onLogin(CODE_OTHER, "connect server failed");
    }
}

void LimClient::onErr(const SockException &ex) {
    WarnL << ex.what();
    manageResponse(CODE_OTHER, ex.what(), true);
    auto status = _status;
    _status = STATUS_LOGOUTED;

    if (status == STATUS_LOGINING && _onLogin) {
        //登录中发生异常
        _onLogin(CODE_OTHER, StrPrinter << "登录时发生错误:" << ex.what());
    }

    if (status == STATUS_LOGINED &&  _onShutdown && ex.getErrCode() != CODE_SUCCESS) {
        //登录后发生错误
        _onShutdown(ex.getErrCode(), ex.what());
    }
}

void LimClient::onRecv(const Buffer::Ptr &pBuf) {
    try {
        onRecvData(pBuf->data(), pBuf->size());
    } catch (ConflictException &ex) {
        WarnL << "挤占掉线:" << ex.what();
        disconnect(CODE_CONFLICT, ex.what());
    } catch (std::exception &ex) {
        WarnL << ex.what();
        disconnect(CODE_OTHER, ex.what());
    }
}

int LimClient::onSendData(const string &data) {
    return send(data);
}

bool LimClient::onProcessRequest(const string &cmd, uint64_t seq, const Value &obj, const string &body) {
    typedef void (LimClient::*onHandleRequest)(uint64_t seq, const Value &obj, const string &body);
    static unordered_map<string, onHandleRequest> map_cmd_fun;
    static onceToken token([&]() {
        map_cmd_fun.emplace("conflict", &LimClient::handleRequest_conflict);
        map_cmd_fun.emplace("push", &LimClient::handleRequest_push);
    }, nullptr);

    auto it = map_cmd_fun.find(cmd);
    if (it == map_cmd_fun.end()) {
        WarnL << "不支持的命令类型:" << cmd << endl;
        sendResponse(seq, CODE_UNSUPPORT, "unsupported cmd", objectValue, "");
        return false;
    }
    auto fun = it->second;
    (this->*fun)(seq, obj, body);
    return true;
}

void LimClient::sendBeat() {
    sendRequest("beat", Json::objectValue, "", [](int code, const string &msg, const Value &obj, const string &body) {
        if (code != CODE_SUCCESS) {
            WarnL << "beat response:" << code << " " << msg;
        }
    });
}

void LimClient::sendRequest_login() {
    Value obj(objectValue);
    obj["uid"] = _uid;
    obj["pwd"] = _pwd;
    obj["info"] = _userInfo;
    sendRequest("login", obj, "", [this](int code, const string &msg, const Value &obj, const string &body) {
        InfoL << "login result:" << code << " " << msg;
        if (code == CODE_JUMP) {
            //跳转服务器
            auto jumpSrvUrl = obj["jumpSrvUrl"].asString();
            uint16_t jumpSrvPort = obj["jumpSrvPort"].asInt();
            InfoL << "jump to:" << jumpSrvUrl << ":" << jumpSrvPort;
            startConnect(jumpSrvUrl, jumpSrvPort);
            return;
        }

        _status = (code == CODE_SUCCESS ? STATUS_LOGINED : STATUS_LOGOUTED);
        if (_onLogin) {
            _onLogin(code, msg);
        }
    });
}

void LimClient::handleRequest_conflict(uint64_t seq, const Value &obj, const string &body) {
    auto ip = obj["ip"].asString();
    sendResponse(seq, CODE_SUCCESS, "", objectValue, body);
    throw ConflictException(ip, obj);
}

void LimClient::handleRequest_push(uint64_t seq, const Value &obj, const string &body) {
    //推送不回复，提高性能
    if(_onPush){
        _onPush(obj, body);
    }
}

void LimClient::onManager() {
    GET_CONFIG(int, timeoutSec, Config::Lim::kTimeoutSec);
    GET_CONFIG(int, beatInterval, Config::Lim::kBeatInterval);
    if (_recvTicker.elapsedTime() >= timeoutSec * 1000) {
        //规定时间内未检测到设备的正常活动（设备可能拔掉网线了或NAT映射结束），断开连接
        WarnL << "与服务器间的连接已超时！";
        disconnect(CODE_TIMEOUT, "connection timeouted");
        return;
    }

    if (_sendTicker.elapsedTime() > beatInterval * 1000) {
        sendBeat();
    }

    manageResponse(CODE_TIMEOUT, "wait for response timeout");
}


} /* namespace Lim */
