#pragma once
#include "IObserver.h"
#include <algorithm>
#include <list>
using std::list;
using std::for_each;
class Observable
{
public:
	Observable(void);
	~Observable(void);

	virtual void add( IObserver* pObserver );
	virtual void notify();
	virtual void remove( IObserver* pObserver );
	virtual void clear();
private:
	list<IObserver*> m_lstObservers;
};

