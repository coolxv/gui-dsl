#include "stdafx.h"
#include "sqlite3/ormlite.h"
#include "inf/IPlugin.h"

using namespace BOT_ORM;
using namespace BOT_ORM::Expression;

/*
struct UserModel
{
	int user_id;
	std::string user_name;
	double credit_count;

	Nullable<int> age;
	Nullable<double> salary;
	Nullable<std::string> title;

	// Inject ORM-Lite into this Class :-)
	ORMAP("UserModel", user_id, user_name, credit_count, age, salary, title);
};
*/


struct User
{
	int user_id;
	std::string user_name;
	double credit_count;

	int age;
	double salary;
	std::string title;


};
struct UserModel :public User
{
	// Inject ORM-Lite into this Class :-)
	ORMAP("UserModel", user_id, user_name, credit_count, age, salary, title);
};

void cmd_init(IPlugin &env, const std::map<std::string, std::string> &parameter, std::vector<std::string> &result)
{
	//数据
	BOT_ORM::ORMapper *ds = (BOT_ORM::ORMapper *)env.GetDS();
	//主程序提供接口
	IDepInj *di = env.GetDI();
	//数据加工
	ds->CreateTbl(UserModel{});

	std::vector<UserModel> initObjs =
	{
		{ 0, "John", 0.2, 21, 1.1,  std::string("Dr.xx") },
		{ 1, "Jack", 0.4, 22, 3.14,  std::string("Dr.jj") },
		{ 2, "Jess", 0.6, 23, 5, std::string("Dr.yy") }
	};

	// Insert Values with Primary Key
	for (const auto &obj : initObjs)
		ds->Insert(obj);
	auto result1 = ds->Query(UserModel{}).ToList();

	result.push_back("hello");
	return;
}


