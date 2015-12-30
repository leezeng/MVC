#include "StdAfx.h"
#include "InstanceMap.h"



template<class T,const char NAME[]>
void InstanceMap<T, NAME>::insert(pair<string,T*> item)
{
	m_pMapInstance->insert(item)
}



 

