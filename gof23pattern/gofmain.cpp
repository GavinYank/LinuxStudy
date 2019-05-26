#include<iostream>
#include "gofmain.h"
using namespace std;

extern "C"
{
	void Gof23PatternMain(void);
}


extern void CompositeMain(void);

void Gof23PatternMain(void)
{
	//SingletonMain();
	//BuilderMain();
	//PrototypeMain();
	cout<<"__builtin_return_address = "<<__builtin_return_address(0)<<endl;
	//cout<<"__builtin_return_address = "<<__builtin_return_address(1)<<endl;
	//BridgeMain();
	DecoratorMain();
	//CompositeMain();
}


















