// ml1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "inf/PluginRegistry.h"
#include "inf/IPlugin.h"
#include "sqlite3/ormlite.h"


// 命令声明，实现在cmd.cpp
void cmd_init(IPlugin &, const std::map<std::string, std::string> &, std::vector<std::string> &);


// 插件实现
class Ml1 : public IPlugin
{
public:
	void* GetDS()
	{
		return (void*)&m_mapper;
	}
protected:
	void InterInit()
	{
		// 命令注册
		{
			m_vec_dispatcher["init"] = cmd_init;
		}
		{
			//m_map_dispatcher["xxx"] = xxx;
		}
		
		{
			//m_vec_map_dispatcher["xxx"] = xxx;
		}

	}

private:
#ifdef _DEBUG
	//BOT_ORM::ORMapper  m_mapper = BOT_ORM::ORMapper("ml1.db");
	BOT_ORM::ORMapper  m_mapper = BOT_ORM::ORMapper(":memory:");
#else
	BOT_ORM::ORMapper  m_mapper = BOT_ORM::ORMapper(":memory:");
#endif // _DEBUG

};

FLAKED_TUNA_EXPORTS_BEGIN
FLAKED_TUNA_PLUGIN(Ml1, IPlugin)
FLAKED_TUNA_EXPORTS_END