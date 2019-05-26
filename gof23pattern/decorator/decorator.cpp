#include "gofmain.h"

Decorator::Decorator(Component* pComp)
{
	this->pComp = pComp;
}

void Decorator::Operation(void)
{
	if(NULL != pComp)
	{
		//pComp->Operation();
	}
}

LockDecorator::LockDecorator(Component* pComp): Decorator(pComp)
{
	
}

void LockDecorator::Operation(void)
{
	printf("Lock\n");
	//Decorator::Operation();
	if(NULL != pComp)
	{
		pComp->Operation();
	}
	printf("Unlock\n");
}

LockDecorator::~LockDecorator(void)
{
	
}

void DecoratorMain(void)
{
	DlistComponent* pDlist = new DlistComponent();

	LockDecorator* pLock = new LockDecorator(pDlist);

	pLock->Operation();

	delete pDlist;
	delete pLock;
}

