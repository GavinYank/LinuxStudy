#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include "gofmain.h"

class Decorator: public Component
{
	public:
		Decorator(Component* pComp);
		
		virtual void Operation(void);
		
	protected:
		Component* pComp;
};

class LockDecorator: public Decorator
{
	public:
		LockDecorator(Component* pComp);

		virtual void Operation(void);
		virtual ~LockDecorator(void);
		
};


extern void DecoratorMain(void);

#endif

