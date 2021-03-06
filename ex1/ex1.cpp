// mvc_c++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using std::cin; 
using std::cout; 
using std::endl; 
using std::flush; 
using std::string; 
using std::vector; 
struct Observer 
{ 
	//update 
	virtual void update(void*)=0; 
}; 
struct Observable 
{ 
	virtual ~Observable(){};
	vector<Observer*>observers; 
	void addObserver(Observer*a){observers.push_back(a);} 
	void notifyObservers() 
	{ 
		for (vector<Observer*>::const_iterator observer_iterator=observers.begin();observer_iterator!=observers.end();observer_iterator++) 
			(*observer_iterator)->update(this); 
	}
}; 
struct Model:Observable 
{ 
	//data members title_caption, version_caption, credits_caption 
	string title_caption; 
	string version_caption; 
	string credits_caption; 
	//data members title, version, credits 
	string title; 
	string version; 
	string credits; 
	//constructor 
	Model():title_caption("Title: "), 
		version_caption("Version: "), 
		credits_caption("Credits: "), 
		title("Simple Model-View-Controller Implementation"), 
		version("0.2"), 
		credits("(put your name here)") 
	{ } 

	//getCredits_Caption, getTitle_Caption, getVersion_Caption 
	string getCredits_Caption(){return credits_caption;} 
	string getTitle_Caption(){return title_caption;} 
	string getVersion_Caption(){return version_caption;} 
	//getCredits, getTitle, getVersion 
	string getCredits(){return credits;} 
	string getTitle(){return title;} 
	string getVersion(){return version;} 
	//setCredits, setTitle, setVersion 
	void setCredits(string a){credits=a;notifyObservers();} 
	void setTitle(string a){title=a;notifyObservers();} 
	void setVersion(string a){version=a;notifyObservers();}  
};

struct TitleView:Observer 
{ 
	void update(void* a) 
	{ 
		cout<<static_cast<Model*>(a)->getTitle_Caption(); 
		cout<<static_cast<Model*>(a)->getTitle(); 
		cout<<endl; 
	} 
}; 
struct VersionView:Observer 
{ 

	void update(void*a) 
	{ 
		cout<<static_cast<Model*>(a)->getVersion_Caption(); 
		cout<<static_cast<Model*>(a)->getVersion(); 
		cout<<endl; 
	} 
}; 
struct CreditsView:Observer 
{ 

	//update 
	void update(void*a) 
	{ 
		cout<<static_cast<Model*>(a)->getCredits_Caption(); 
		cout<<static_cast<Model*>(a)->getCredits(); 
		cout<<endl; 
	} 
}; 
struct Views:Observer 
{ 
	//data members titleview, versionview, creditsview 
	TitleView titleview; 
	VersionView versionview; 
	CreditsView creditsview;   
	void reg(Observable* a) 
	{ 
		a->addObserver(&titleview); 
		a->addObserver(&versionview); 
		a->addObserver(&creditsview); 
		a->addObserver(this); 
	} 

	//update 
	void update(void*a) 
	{ 
		cout<<"_____________________________"; 
		cout<<"\nType t to edit Title, "; 
		cout<<"v to edit Version, "; 
		cout<<"c to edit Credits. "; 
		cout<<"Type q to quit.\n>>"; 
	} 
}; 
struct Controller
{ 
	Model*model; 
	void setModel(Model&a){model=&a;} 
	void MessageLoop() 
	{ 
		char c=' '; 
		string s; 
		while(c!='q') 
		{ 
			cin>>c; 
			cin.ignore(256,'\n'); 
			cin.clear(); 
			switch(c) 
			{ 
			case 'c': 
			case 't': 
			case 'v': 
				getline(cin,s); 
				break; 
			} 
			switch(c) 
			{ 
			case 'c':model->setCredits(s);break; 
			case 't':model->setTitle(s);break; 
			case 'v':model->setVersion(s);break; 
			} 
		} 
	} 
	 

}; 
struct Application 
{ 
	//data member model 
	Model model; 
	//data member views 
	Views views; 
	//data member controller 
	Controller controller; 
	//constructor 
	Application() 
	{ 
		views.reg(&model); 
		controller.setModel(model); 
		model.notifyObservers(); 
	} 
	//run 
	void run(){controller.MessageLoop();} 
}; 
int _tmain(int argc, _TCHAR* argv[])
{
	Application().run(); 
	getchar();
	return 0;
}

