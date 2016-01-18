#pragma once
#include "Observable.h"
#include "IObserver.h"
class Observer1:public IObserver
{
public:
	Observer1(void);
	~Observer1(void);

	virtual bool update( Observable* pObservable );

};

class Observer2:public IObserver
{
public:
	Observer2(void);
	~Observer2(void);

	virtual bool update( Observable* pObservable );

};
