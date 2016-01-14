#pragma once
#include <string>
#include <map>
#include <utility>  
template<class T,const char NAME[]>
class InstanceMap
{
public:
	InstanceMap();
	void insert(std::pair<std::string,T*> item);
	T* find(const std::string& key);
	virtual ~InstanceMap(void);
	void remove(const std::string& key);
private:
	std::map<std::string,T*>* m_pMapInstance;
};  

