#pragma once
#include "ICommand.h"
#include "IProxy.h"
#include "IMediator.h"
class IFacade
{
public:
	IFacade(void);
	~IFacade(void);
	virtual void registerProxy(IProxy* proxy) = 0;
	virtual IProxy const& retrieveProxy(std::string const& proxy_name) const = 0;
	virtual IProxy& retrieveProxy(std::string const& proxy_name) = 0;
	virtual IProxy* removeProxy(std::string const& proxy_name) = 0;
	virtual bool hasProxy(std::string const& proxy_name) const = 0;
	virtual void registerCommand(std::string const& notification_name, ICommand* command) = 0;
	virtual ICommand const& retrieveCommand(std::string const& notification_name) const = 0;
	virtual ICommand& retrieveCommand(std::string const& notification_name) = 0;
	virtual ICommand* removeCommand(std::string const& notification_name) = 0;
	virtual bool hasCommand(std::string const& notification_name) const = 0;
	virtual void registerMediator(IMediator* mediator) = 0;
	virtual IMediator const& retrieveMediator(std::string const& mediator_name) const = 0;
	virtual IMediator& retrieveMediator(std::string const& mediator_name) = 0;
	virtual IMediator* removeMediator(std::string const& mediator_name) = 0;
	virtual bool hasMediator(std::string const& mediator_name) const = 0;
	virtual void notifyObservers(INotification const& notification) = 0;
};

