// MVC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "IModel.h"
#include "IController.h"
#include "InstanceMap.h"

extern const char ModelName[];
const char ModelName[] ="Model";
InstanceMap<IModel,ModelName> _Model_;

extern const char ControllerName[];
const char ControllerName[]="Controller";
InstanceMap<IController,ControllerName> _Controller_;

int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

