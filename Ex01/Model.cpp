#include "StdAfx.h"
#include "Model.h"


Model::Model(void)
{
}


Model::~Model(void)
{
}

void Model::changed( int nValue )
{
	m_nValue=nValue;
	notify();
}
