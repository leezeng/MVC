#include "StdAfx.h"
#include "Notifier.h"


Notifier::Notifier(void)
{
}


Notifier::~Notifier(void)
{
}

std::string const& Notifier::getMultitonKey( void ) const
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Notifier::sendNotification( std::string const& notification_name, void const* body /*= NULL*/, std::string const& type /*= "" */ )
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Notifier::initializeNotifier( std::string const& key )
{
	throw std::logic_error("The method or operation is not implemented.");
}
