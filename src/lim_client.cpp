#include <stdlib.h>
#include <memory.h>
#include <signal.h>
#include <iostream>
#include <iostream>
#include <iomanip>
#include <list>
#include <ctime>
#include "Util/CMD.h"
#include "Util/util.h"
#include "Util/mini.h"
#include "Util/logger.h"
#include "Util/NoticeCenter.h"
#include "Poller/EventPoller.h"
#include "Thread/WorkThreadPool.h"
#include "Config.h"
#include "LimClient.h"

using namespace std;
using namespace Lim;
using namespace Config;
using namespace toolkit;

class CMD_main : public CMD {
public:
    CMD_main() {
        _parser.reset(new OptionParser(nullptr));

        (*_parser) << Option('l',/*该选项简称，如果是\x00则说明无简称*/
                             "level",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             to_string(LTrace).data(),/*该选项默认值*/
                             false,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "日志等级,LTrace~LError(0~4)",/*该选项说明文字*/
                             nullptr);

        (*_parser) << Option('t',/*该选项简称，如果是\x00则说明无简称*/
                             "threads",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             "1",/*该选项默认值*/
                             false,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "启动事件触发线程数",/*该选项说明文字*/
                             nullptr);

        (*_parser) << Option('S',/*该选项简称，如果是\x00则说明无简称*/
                             "server",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             "safe.lim.app",/*该选项默认值*/
                             true,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "服务器域名或ip",/*该选项说明文字*/
                             nullptr);

        (*_parser) << Option('P',/*该选项简称，如果是\x00则说明无简称*/
                             "port",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             "10000",/*该选项默认值*/
                             true,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "服务器端口号",/*该选项说明文字*/
                             nullptr);

        (*_parser) << Option('u',/*该选项简称，如果是\x00则说明无简称*/
                             "user",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             "xzl",/*该选项默认值*/
                             true,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "登录用户名",/*该选项说明文字*/
                             nullptr);

        (*_parser) << Option('p',/*该选项简称，如果是\x00则说明无简称*/
                             "pwd",/*该选项全称,每个选项必须有全称；不得为null或空字符串*/
                             Option::ArgRequired,/*该选项后面必须跟值*/
                             "111111",/*该选项默认值*/
                             true,/*该选项是否必须赋值，如果没有默认值且为ArgRequired时用户必须提供该参数否则将抛异常*/
                             "登录用户密码",/*该选项说明文字*/
                             nullptr);
    }

    virtual ~CMD_main() {}

    virtual const char *description() const {
        return "主程序命令参数";
    }
};


int main(int argc, char *argv[]) {
    {
        CMD_main cmd_main;
        try {
            cmd_main.operator()(argc, argv);
        } catch (std::exception &ex) {
            cout << ex.what() << endl;
            return -1;
        }

        LogLevel logLevel = (LogLevel) cmd_main["level"].as<int>();
        logLevel = std::min(std::max(logLevel, LTrace), LError);
        int threads = cmd_main["threads"];
        string name = cmd_main["user"];
        string pwd = cmd_main["pwd"];

        //设置日志
        Logger::Instance().add(std::make_shared<ConsoleChannel>("ConsoleChannel", logLevel));
        Logger::Instance().setWriter(std::make_shared<AsyncLogWriter>());

        //加载配置文件，如果配置文件不存在就创建一个
        Config::loadIniConfig();

        //设置线程数
        WorkThreadPool::Instance().setPoolSize(threads);
        EventPollerPool::setPoolSize(threads);

        static atomic_int push_count(0);
        LimClient::Ptr client = std::make_shared<LimClient>();
        DebugL << "开始登陆: " << name << " " << pwd;
        client->login(cmd_main["server"], cmd_main["port"], name, pwd, Value());
        client->setOnLogin([name](int code, const string &msg) {
            if (code != 0) {
                WarnL << name << " 登陆失败:" << msg;
            } else {
                InfoL << name << " 登陆成功";
            }
        });
        client->setOnShutdown([name](int code, const string &msg) {
            WarnL << name << " 掉线:" << code << "(" << msg << ")";
        });
        client->setOnPush([name](const Value &obj,const string &body){
            DebugL << "用户 " << name << " 收到推送，总条数:" << ++push_count << ",类型为:" << obj["type"].asInt()
                    << ",数据类型为:" << (obj["json_or_pb"].asBool() ? "json" : "protobuf")  << ",内容为:" << body;
        });

        //设置退出信号处理函数
        static semaphore sem;
        signal(SIGINT, [](int) {
            InfoL << "SIGINT:exit";
            signal(SIGINT, SIG_IGN);
            sem.post();
        });// 设置退出信号
        signal(SIGHUP, [](int) { Config::loadIniConfig(); });
        sem.wait();
    }

    return 0;
}
