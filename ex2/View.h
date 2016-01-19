#pragma once
#include "Observer.h"
 struct  IView
 {
	 virtual void registerObserver(std::string const& notification_name, IObserver* observer) = 0;
	 virtual void notifyObservers(Notification const& notification) = 0;
 };
 class View : public virtual IView
 {
 public:
	 virtual void registerObserver (std::string const& notification_name, IObserver* observer)
	 {
		 std::map<std::string, IObserver*>::value_type item(notification_name, observer);
		_observers.insert(item);
	 }
	 virtual void notifyObservers(Notification const& notification)
	 {
		std::list<IObserver*> lst;
		for (std::map<std::string, IObserver*>::iterator iter=_observers.find(notification.getName());iter!=_observers.end()&&iter->first==notification.getName();iter++)
		{
			lst.push_back(iter->second);
		}
		for (std::list<IObserver*>::iterator iter=lst.begin();iter!=lst.end();iter++)
		{
			(*iter)->notifyObserver(notification);
		}
	 }
 private:
	 std::map<std::string, IObserver*> _observers;
 };