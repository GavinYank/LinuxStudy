#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

#include<iostream>
using namespace std;

class Prototype
{
	public:
		Prototype(int ii);
		//Prototype(void);
		virtual Prototype* Clone(void) = 0;
};


class ConcretePrototype: public Prototype
{
	public:
		ConcretePrototype(void);
		ConcretePrototype(const ConcretePrototype& cp);
		virtual Prototype* Clone(void);

	private:
		int i;
};


extern void PrototypeMain(void);

#endif

