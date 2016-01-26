// ex3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <string>

struct Command
{
	virtual void execute()=0;
};
class Light
{
public:
	void On(){
		printf("ON\r\n");
	}
	void Off(){
		printf("OFF\r\n");
	}
};

class LightOffCommand:Command
{
public:
	LightOffCommand(Light*p):pLight(p){}
	virtual void execute() 
	{
		pLight->Off();
	}
private:
	Light* pLight;
};
class LightOnCommand:Command
{
public:
	LightOnCommand(Light*p):pLight(p){}
	virtual void execute() 
	{
		pLight->On();
	}
private:
	Light* pLight;
};

class RemoteControl
{
public:
	RemoteControl()
	{
	}
	void Register(std::string s,Command* c){
		_commands[s]=c;
	}
	void On(){
		_commands["on"]->execute();
	}
	void Off(){
		_commands["off"]->execute();
	}
private:
	std::map<std::string,Command*> _commands; 
};


int _tmain(int argc, _TCHAR* argv[])
{
	Light light;
	LightOffCommand offCmd(&light);
	LightOnCommand onCmd(&light);

	RemoteControl c;
	c.Register("on",(Command*)&onCmd);
	c.Register("off",(Command*)&offCmd);

	c.Off();
	c.On();
	getchar();
	return 0;
}

