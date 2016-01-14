#pragma once
#include <string>
class INotifier
{ 
public:
	virtual void sendNotification(std::string const& notification_name, void const* body = NULL, std::string const& type = "") = 0;
	virtual void initializeNotifier(std::string const& key) = 0;
	virtual std::string const& getMultitonKey(void) const = 0;
	virtual ~INotifier(void);
};

