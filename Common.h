#pragma once
#include "IModel.h"
#include "IController.h"
#include "InstanceMap.h"

extern const char ModelName[];
extern InstanceMap<IModel,ModelName> _Model_;

/*
const char ControllerName[]="Controller";
extern const char ControllerName[];

InstanceMap<IController,ControllerName> _Controller_;*/
