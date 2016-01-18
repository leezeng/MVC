#pragma once
#include "Observable.h"
class Subject:public Observable
{
public:
	Subject(void);
	~Subject(void);
	void changed();
};

