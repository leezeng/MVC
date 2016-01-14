#pragma once
#include "IProxy.h"
#include <list>
#include <string>
class IModel
{
public:
	IModel();
	virtual ~IModel(void);
	virtual void registerProxy(IProxy* proxy) = 0;
	virtual IProxy const& retrieveProxy(std::string const& proxy_name) const = 0;
	virtual IProxy& retrieveProxy(std::string const& proxy_name) = 0;
	virtual IProxy* removeProxy(std::string const& proxy_name) = 0;
	virtual bool hasProxy(std::string const& proxy_name) const = 0;
	virtual std::list<std::string> listProxyNames(void) const = 0;
};

