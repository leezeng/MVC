#pragma once
#include "Observable.h"
class Model:public Observable
{
public:
	Model(void);
	~Model(void);
	void changed(int nValue);
private:
	int m_nValue;
};

