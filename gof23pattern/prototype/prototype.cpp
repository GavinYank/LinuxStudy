#include "gofmain.h"


Prototype::Prototype(int ii)
{
	//cout<<__func__<<endl;
	cout<<"ii"<<ii<<endl;
}
#if 0
Prototype::Prototype(void)
{
	cout<<__func__<<endl;
	//cout<<"ii"<<ii<<endl;
}
#endif
ConcretePrototype::ConcretePrototype(void):Prototype(78)
{
	//Prototype::Prototype(56);
	i = 12;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype& cp)
					:Prototype(15)
{
	cout<<cp.i<<__func__<<" deeply copy"<<endl;
}

Prototype* ConcretePrototype::Clone(void)
{
	ConcretePrototype* p = new ConcretePrototype(*this);
	return p;
}


void PrototypeMain(void)
{
	Prototype* p = new ConcretePrototype();
	Prototype* p2 = p->Clone();

	p2 = p2;

	cout<<"sizeof(p2) = "<<sizeof(p2)<<endl;
}

