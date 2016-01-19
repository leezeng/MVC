#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
using std::cin; 
using std::cout; 
using std::endl; 
using std::flush; 
using std::string; 
using std::vector; 
struct Notification
{
	Notification(std::string const& name, void const* body = NULL, std::string const& type = ""):_name(name),_body(body),_type(type){}
	std::string const& getName(void) const {return _name;};
	virtual void setBody(void const* body) {_body=body;};
	virtual void setType(std::string const& type){_type=type;};
	virtual void const* getBody(void) const {return _body;};
	virtual std::string const& getType(void) const{return _type;}; 
	virtual ~Notification(void){};
private:
	std::string _name;
	void const* _body;
	std::string _type;
}; 

struct  IObserver
{
	virtual void notifyObserver(Notification const& notification) = 0;
	virtual bool compareNotifyContext(void const* object) const = 0;
	virtual ~IObserver(void){};
};

template<typename _Method, typename _Context>
class Observer : public IObserver
{
private:
	Observer(void);
public:

	explicit Observer(Observer const& arg)
		: IObserver()
		, _notify_method(arg._notify_method)
		, _notify_context(arg._notify_context)
	{ }

public:

	explicit Observer(_Method notify_method, _Context* notify_context)
		: IObserver()
		, _notify_method(notify_method)
		, _notify_context(notify_context)
	{ }


	virtual void notifyObserver(Notification const& notification)
	{
		if (_notify_context == NULL)
			throw std::runtime_error("Notify context is null.");
		if (_notify_method == NULL)
			throw std::runtime_error("Notify method is null.");
		(*_notify_context.*_notify_method)(notification);
	}

	virtual bool compareNotifyContext(void const* object) const
	{
		return _notify_context == object;
	}

	Observer& operator=(Observer const& arg)
	{
		_notify_method = arg._notify_method;
		_notify_context = arg._notify_context;
		return *this;
	}

	virtual ~Observer(void)
	{ }
private:
	_Method _notify_method;
	_Context* _notify_context;
};

template<typename _Method, typename _Context>
inline IObserver* createObserver(_Method notify_method, _Context* notify_context)
{
	return new Observer<_Method, _Context>(notify_method, notify_context);
} 
template<typename _Method, typename _Context>
inline Observer<_Method, _Context> makeObserver(_Method notify_method, _Context* notify_context)
{
	return Observer<_Method, _Context>(notify_method, notify_context);
} 