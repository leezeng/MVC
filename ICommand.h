#pragma once
#include "INotification.h"
#include "INotifier.h"
#include <string>
class ICommand:public virtual INotifier
{
public:
	ICommand(void);
	~ICommand(void);
	virtual void execute(INotification const& notification) = 0;
};

