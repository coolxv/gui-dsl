#include "stdafx.h"
#include "inf/IPlugin.h"
#include "sqlite3/ormlite.h"
#include "sqlite3/nullable.h"

void cmd_init(IPlugin &env, const std::map<std::string, std::string> &parameter, std::vector<std::string> &result)
{
	//����
	BOT_ORM::ORMapper *ds = (BOT_ORM::ORMapper *)env.GetDS();
	//�������ṩ�ӿ�
	IDepInj *di = env.GetDI();
	//���ݼӹ�
	result.push_back("hello");
	return;
}


