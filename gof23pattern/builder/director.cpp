#include "gofmain.h"



Director::Director(Builder* bld)
{ 
	_bld = bld;
} 
Director::~Director()
{ 
} 

void Director::Construct() 
{ 
	_bld->BuildPartA("user-defined-1"); 
	_bld->BuildPartB("user-defined-2"); 
	_bld->BuildPartC("user-defined-3"); 
} 


