#include "stdafx.h"
#include "inf/IPlugin.h"
#include "sqlite3/ormlite.h"
#include "sqlite3/nullable.h"

void cmd_init(IPlugin &env, const std::map<std::string, std::string> &parameter, std::vector<std::string> &result)
{
	//数据
	BOT_ORM::ORMapper *ds = (BOT_ORM::ORMapper *)env.GetDS();
	//主程序提供接口
	IDepInj *di = env.GetDI();
	//数据加工
	result.push_back("hello");
	return;
}


