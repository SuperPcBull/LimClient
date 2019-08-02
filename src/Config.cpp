/*
 * Config.cpp
 *
 *  Created on: 2017年6月12日
 *      Author: xzl
 */

#include "Config.h"

namespace Config {

bool loadIniConfig(const char *ini_path){
	string ini;
	if(ini_path && ini_path[0] != '\0'){
		ini = ini_path;
	}else{
		ini = exePath() + ".ini";
	}
	try{
		mINI::Instance().parseFile(ini);
		NoticeCenter::Instance().emitEvent(Broadcast::kBroadcastReloadConfig);
		return true;
	}catch (std::exception &ex) {
		InfoL << "dump ini file to:" << ini;
		mINI::Instance().dumpFile(ini);
		return false;
	}
}

namespace Broadcast{
const string kBroadcastReloadConfig = "kBroadcastReloadConfig";
}//Broadcast

namespace Lim{
#define LIM_FIELD "lim."
const string kTimeoutSec = LIM_FIELD"timeoutSec";
const string kBeatInterval = LIM_FIELD"beatInterval";
const string kResTimeoutSec = LIM_FIELD"resTimeoutSec";
static onceToken token([](){
	mINI::Instance()[kTimeoutSec] = 45;
	mINI::Instance()[kBeatInterval] = 15;
	mINI::Instance()[kResTimeoutSec] = 15;
},nullptr);
}//lim


} /* namespace Config */
