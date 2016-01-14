#pragma once
#include "INotifier.h"
class IProxy:public virtual INotifier
{
public:
	virtual ~IProxy(void);
	virtual std::string const& getProxyName(void) const = 0;
	virtual void setData(void const* data) = 0;
	virtual void const* getData(void) const = 0;
	virtual void onRegister(void) = 0;
	virtual void onRemove(void) = 0;
};

