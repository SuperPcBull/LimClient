/*
 * Config.h
 *
 *  Created on: 2017年6月12日
 *      Author: xzl
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "Util/mini.h"
#include "Util/logger.h"
#include "Util/onceToken.h"
#include "Util/NoticeCenter.h"

using namespace toolkit;

namespace Config {

//加载配置文件，如果配置文件不存在，那么会导出默认配置并生成配置文件
//加载配置文件成功后会触发kBroadcastUpdateConfig广播
//如果指定的文件名(ini_path)为空，那么会加载默认配置文件
//默认配置文件名为 /path/to/your/exe.ini
//加载配置文件成功后返回true，否则返回false
bool loadIniConfig(const char *ini_path = nullptr);

namespace Broadcast{


//更新配置文件事件广播,执行loadIniConfig函数加载配置文件成功后会触发该广播
extern const string kBroadcastReloadConfig;
#define BroadcastReloadConfigArgs void

#define ReloadConfigTag  ((void *)(0xFF))
#define RELOAD_KEY(arg,key) \
    do{ \
        decltype(arg) arg##tmp = mINI::Instance()[key]; \
        if(arg != arg##tmp ) { \
            arg = arg##tmp; \
            InfoL << "reload config:" << key << "=" <<  arg; \
        } \
    }while(0);

//监听某个配置发送变更
#define LISTEN_RELOAD_KEY(arg,key) \
    do{ \
        static onceToken s_token([](){ \
            NoticeCenter::Instance().addListener(ReloadConfigTag,Config::Broadcast::kBroadcastReloadConfig,[](BroadcastReloadConfigArgs){ \
                RELOAD_KEY(arg,key); \
            }); \
        }); \
    }while(0);

#define GET_CONFIG(type,arg,key) \
        static type arg = mINI::Instance()[key]; \
        LISTEN_RELOAD_KEY(arg,key);

}//Broadcast

namespace Lim{
//会话超时时间,单位秒，默认45秒
extern const string kTimeoutSec;
//心跳时间间隔，单位秒，默认15秒
extern const string kBeatInterval;
//回复超时时间，单位秒。默认15秒，不要随意修改
extern const string kResTimeoutSec;
}//Lim

} /* namespace Config */

#endif /* CONFIG_H_ */
