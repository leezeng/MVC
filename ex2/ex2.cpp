// mvc_c++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Observer.h"
#include "View.h"

struct ICommand
{
	virtual void execute(Notification const& notification) = 0;
	virtual ~ICommand(void){};
};
class Controller
{
public:
	Controller(IView* view):_View(view){};
	virtual void registerCommand(std::string const& notification_name, ICommand* command)
	{
		if (_commands.find(notification_name)==_commands.end())
		{
			IObserver* observer = createObserver(&Controller::executeCommand, this);
			_View->registerObserver(notification_name,observer);
		}
		_commands[notification_name] =  command;
	}
	virtual void executeCommand(Notification const& notification)
	{
		std::map<std::string, ICommand*>::iterator iter=_commands.find(notification.getName());
		if (iter!=_commands.end())
		{
			iter->second->execute(notification);
		}
	}
private:
	std::map<std::string, ICommand*> _commands;
	IView* _View;
};
class  SimpleCommand 
	: public virtual ICommand
{
	virtual void execute(Notification const& notification){

	};
};
class  MacroCommand:public virtual ICommand
{
public:
	virtual void addSubCommand(ICommand* command){_commnds.push_back(command);};
	virtual void execute(Notification const& notification){
		std::list<ICommand*>::iterator iter=_commnds.begin();
		while (iter!=_commnds.end())
		{
			(*iter)->execute(notification);
			_commnds.erase(iter);
		}
	};
private:
	std::list<ICommand*> _commnds;
	IView* _view;
};

struct Args
{
	int input1;
	int input2;
	int result;
	Args(int input1,int input2)
	{
		this->input1=input1;
		this->input2=input2;
		this->result = 0;
	}
}; 
class AddSimpleCommand:public SimpleCommand
{
public:
	virtual void execute( Notification const& notification ) 
	{
		Args* p=(Args*)notification.getBody();
		p->result=p->input1+p->input2;
		printf("+ :%d\r\n",p->result);
	}
}; 
class MinusSimpleCommand:public SimpleCommand
{
public:
	virtual void execute( Notification const& notification ) 
	{
		Args* p=(Args*)notification.getBody();
		p->result=p->input1-p->input2;
		printf("- :%d\r\n",p->result);
	}
}; 

struct Application 
{  
	View view;
	Controller contorller;

	MinusSimpleCommand test1;
	AddSimpleCommand test2;
	Application(): contorller(&view)
	{ 
		contorller.registerCommand("test-",&test1);
		contorller.registerCommand("test+",&test2);
	} 
	void run()
	{
		char c=' '; 
		string s; 
		while(c!='q') 
		{ 
			cin>>c; 
			cin.ignore(256,'\n'); 
			cin.clear(); 

			//getline(cin,s); 

			switch(c) 
			{ 
			case '+':
				{
					Args args(1,2);
					Notification note("test+",&args);
					view.notifyObservers(note);
					break;

				}
			case '-':
				{
					Args args(1,2);
					Notification note("test-",&args);
					view.notifyObservers(note);
					break;
				}
			} 
		} 


	}
}; 
int _tmain(int argc, _TCHAR* argv[])
{
	Application().run();

	getchar();
	return 0;
}

