#include "StdAfx.h"
#include "Observer.h"


Observer1::Observer1(void)
{
}


Observer1::~Observer1(void)
{
}

bool Observer1::update( Observable* pObservable )
{
	 printf("obser 1 %x\r\n",pObservable);
	 return true;
}

Observer2::Observer2( void )
{

}

Observer2::~Observer2( void )
{

}

bool Observer2::update( Observable* pObservable )
{
	 printf("obser 2 %x\r\n",pObservable);
	return true;
}
