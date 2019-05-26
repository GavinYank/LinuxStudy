
#include "gofmain.h"


Singleton* Singleton::_instance = NULL;

Singleton* Singleton::Instance(int dLine)
{
	if(NULL == Singleton::_instance)
	{
		_instance = new Singleton();
		cout<<"dLine = "<<dLine<<endl;
	}

	return (Singleton::_instance);
}
		

Singleton::Singleton()
{
	cout<<__func__<<endl;
}


void SingletonMain(void)
{
	Singleton *p = Singleton::Instance(__LINE__);

	p = p;

	Singleton *pp = Singleton::Instance(__LINE__);

	pp = pp;
}

