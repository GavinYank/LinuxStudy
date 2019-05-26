

#include "gofmain.h"

#include <iostream> 
using namespace std;
AbstractionImp::AbstractionImp() 
{
}
AbstractionImp::~AbstractionImp() 
{
}
void AbstractionImp::Operation() 
{ 
	cout<<"AbstractionImp....imp..."<<endl; 
}

ConcreteAbstractionImpA::ConcreteAbstractionImpA() 
{
	
}
ConcreteAbstractionImpA::~ConcreteAbstractionImpA() 
{
	cout<<__func__<<endl;
}

void ConcreteAbstractionImpA::Operation() 
{ 
	cout<<"ConcreteAbstractionImpA...."<<endl; 
}

ConcreteAbstractionImpB::ConcreteAbstractionImpB() 
{
	
}
ConcreteAbstractionImpB::~ConcreteAbstractionImpB() 
{
}
void ConcreteAbstractionImpB::Operation() 
{ 
	cout<<"ConcreteAbstractionImpB...."<<endl; 
}

void BridgeMain(void)
{
	AbstractionImp* imp = new ConcreteAbstractionImpA();
	Abstraction* abs = new RefinedAbstraction(imp);
	
	abs->Operation();

	delete imp;
	delete abs;
}

