#pragma once
#include <string>
#include <map>
#include <utility> 
using std::string;
using std::map;
using std::pair; 
template<class T,const char NAME[]>
class InstanceMap
{
public:
	InstanceMap(void):m_pMapInstance(nullptr){
		m_pMapInstance=new map<string,T*>();
	};
	void insert(pair<string,T*> item);
	virtual ~InstanceMap(void){
		if (nullptr!=m_pMapInstance)
		{
			for (map<string,T*>::iterator iter=m_pMapInstance->begin();iter!=m_pMapInstance->end();iter++)
			{
				delete iter->second;
			}
			m_pMapInstance->clear();
			delete m_pMapInstance;
		 
		}
	}; 
private:
	map<string,T*>* m_pMapInstance;
}; 