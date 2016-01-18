// Observer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Observer.h"
#include "Subject.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Observer1 obs;
	Observer1 ob2;
	Subject s;
	s.add(&obs);
	s.add(&ob2);
	s.changed();
	system("pause");
	return 0;
}

