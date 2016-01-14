#pragma once
#include "INotifier.h"
#include "IFacade.h"
class Notifier:public virtual INotifier
{
public:
	explicit Notifier(void);
	explicit Notifier(Notifier const& arg);
	~Notifier(void);

	virtual std::string const& getMultitonKey( void ) const;

	virtual void sendNotification( std::string const& notification_name, void const* body = NULL, std::string const& type = "" );

	virtual void initializeNotifier( std::string const& key );
protected:
	IFacade& getFacade();
	std::string _multiton_key;
	static char const* const MULTITON_MSG;
};

