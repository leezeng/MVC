#pragma once
class Observable;
struct IObserver
{
	virtual bool update(Observable* pObservable)=0;
};

