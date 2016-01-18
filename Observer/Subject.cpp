#include "StdAfx.h"
#include "Subject.h"


Subject::Subject(void)
{
}


Subject::~Subject(void)
{
}

void Subject::changed()
{
	notify();
}
