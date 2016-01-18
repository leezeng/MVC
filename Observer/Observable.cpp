#include "StdAfx.h"
#include "Observable.h"


Observable::Observable(void)
{
}


Observable::~Observable(void)
{
}

void Observable::add( IObserver* pObserver )
{
	m_lstObservers.push_back(pObserver);
}

void Observable::notify()
{
	for_each(m_lstObservers.begin(),m_lstObservers.end(),[this](IObserver* p){
		p->update(this);
	});
}

void Observable::remove( IObserver* pObserver )
{
	m_lstObservers.remove(pObserver);
}

void Observable::clear()
{
	m_lstObservers.clear();
}
