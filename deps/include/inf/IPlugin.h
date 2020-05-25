#ifndef _I_PLUGIN_H_
#define _I_PLUGIN_H_

#include <string>
#include <vector>
#include <map>


class IDepInj
{
public:

};

class IPlugin
{
public://主程序可用接口
	void InitPlugin(IDepInj *idi)
	{
		m_idi = idi;
		InterInit();
	}
	void Command(std::string cmd)
	{
		auto it = m_dispatcher.find(cmd);
		if (it != m_dispatcher.end())
		{
			it->second(*this);
		}
		return;
	}
	void Command(const std::string cmd,
				const std::map<std::string, std::string> &parameter, 
				std::vector<std::string> &result)
	{
		auto it = m_vec_dispatcher.find(cmd);
		if (it != m_vec_dispatcher.end())
		{
			it->second(*this, parameter, result);
		}
		return;
	}
	void Command(const std::string cmd,
				const std::map<std::string, std::string> &parameter,
				std::map<std::string, std::string> &result)
	{
		auto it = m_map_dispatcher.find(cmd);
		if (it != m_map_dispatcher.end())
		{
			it->second(*this, parameter, result);
		}
		return;
	}
	void Command(std::string cmd,
				const std::map<std::string, std::string> &parameter,
				std::vector<std::map<std::string, std::string>> &result)
	{
		auto it = m_vec_map_dispatcher.find(cmd);
		if (it != m_vec_map_dispatcher.end())
		{
			 it->second(*this, parameter, result);
		}
		return;
	}
public:
	//插件可用接口
	IDepInj * GetDI()
	{
		return m_idi;
	}
	//插件需要实现的接口
	virtual void* GetDS() = 0;
protected:
	virtual void InterInit() = 0;
protected:
	IDepInj *m_idi = nullptr;
	typedef void(*RET_P)(IPlugin&);
	std::map<std::string, RET_P> m_dispatcher;
	typedef void (*RET_VEC_P)(IPlugin&, const std::map<std::string, std::string>&, std::vector<std::string>&);
	std::map<std::string, RET_VEC_P> m_vec_dispatcher;
	typedef void (*RET_MAP_P)(IPlugin&, const std::map<std::string, std::string>&, std::map<std::string, std::string>&);
	std::map<std::string, RET_MAP_P> m_map_dispatcher;
	typedef void (*RET_VEC_MAP_P)(IPlugin&, const std::map<std::string, std::string>&, std::vector<std::map<std::string, std::string>>&);
	std::map<std::string, RET_VEC_MAP_P> m_vec_map_dispatcher;
};


#endif