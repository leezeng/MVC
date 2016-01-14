#include "StdAfx.h"
#include "InstanceMap.h"


template<class T,const char NAME[]>
InstanceMap<T, NAME>::~InstanceMap( void )
{
	if (nullptr!=m_pMapInstance)
	{
		for (std::map<string,T*>::iterator iter=m_pMapInstance->begin();iter!=m_pMapInstance->end();iter++)
		{
			delete iter->second;
		}
		m_pMapInstance->clear();
		delete m_pMapInstance;
	}
}




template<class T,const char NAME[] >
InstanceMap<T, NAME>::InstanceMap():m_pMapInstance(nullptr)
{
	m_pMapInstance=new map<string,T*>();
};


template<class T,const char NAME[]>
void InstanceMap<T, NAME>::insert(std::pair<std::string,T*> item)
{
	m_pMapInstance->insert(item); 
}


template<class T,const char NAME[]>
T* InstanceMap<T, NAME>::find( const std::string& key )
{
	return m_pMapInstance->find(key);
}


template<class T,const char NAME[]>
void InstanceMap<T, NAME>::remove( const std::string& key )
{
	std::map<std::string,T*>::iterator iter=m_pMapInstance->find(key);
	if (iter!=m_pMapInstance->end())
	{
		m_pMapInstance->erase(iter);
	}
}


