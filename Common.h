#pragma once
#include "IModel.h"
#include "IController.h"
#include "InstanceMap.h"
const char ControllerName[]="Controller";
extern const char ModelName[];
InstanceMap<IModel,ModelName> _Model_;



/*
const char ControllerName[]="Controller";
extern const char ControllerName[];

InstanceMap<IController,ControllerName> _Controller_;*/
