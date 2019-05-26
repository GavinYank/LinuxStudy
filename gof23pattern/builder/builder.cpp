
#include "gofmain.h"

Builder::Builder() 
{ 
} 

Builder::~Builder() 
{ 
} 

ConcreteBuilder::ConcreteBuilder() 
{ 
} 

ConcreteBuilder::~ConcreteBuilder() 
{ 
} 

void ConcreteBuilder::BuildPartA(const string& buildPara)
{ 
	cout<<"Step1:Build PartA..."<<buildPara<<endl; 
} 

void ConcreteBuilder::BuildPartB(const string& buildPara)
{ 
	cout<<"Step2:Build PartB..."<<buildPara<<endl; 
} 
void ConcreteBuilder::BuildPartC(const string& buildPara)
{ 
	cout<<"Step3:Build PartC..."<<buildPara<<endl; 
} 

Product* ConcreteBuilder::GetProduct() 
{ 
	BuildPartA("pre-defined-1"); 
	BuildPartB("pre-defined-2"); 
	BuildPartC("pre-defined-3"); 
	
	return new Product(); 
}



void BuilderMain(void)
{
	ConcreteBuilder* b = new ConcreteBuilder();
	Director* d = new Director(b);
	
	d->Construct();
	b->GetProduct();
}





