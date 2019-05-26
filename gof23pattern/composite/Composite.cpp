#include"Composite.h" 
#include"CompositeComponent.h" 
//#define NULL 0   //define NULLPOINTOR 
Composite::Composite() 
{ 
	//vector<Component*>::iteratoritend= 
	comVec.begin();
} 
Composite::~Composite() 
{ 
} 
void Composite::Operation() 
{ 
	vector<ComponentMy*>::iterator comIter = comVec.begin();
	
	for (;comIter != comVec.end();comIter++) 
	{ 
		(*comIter)->Operation(); 
	} 
} 
void Composite::Add(ComponentMy* com) 
{ 
	comVec.push_back(com); 
} 
void Composite::Remove(ComponentMy* com) 
{ 
	com = com;
	//comVec.pop_back(com); 
	comVec.pop_back();
} 
ComponentMy* Composite::GetChild(int index) 
{ 
	return comVec[index]; 
}


#include"CompositeComponent.h" 
#include"Composite.h" 
#include"Leaf.h" 
#include<iostream> 

using namespace std; 

void CompositeMain(void)
{ 
	Leaf*l = new Leaf(); 
	l->Operation(); 
	Composite* com = new Composite(); 
	com->Add(l); 
	com->Operation(); 
	ComponentMy* ll = com->GetChild(0); 
	ll->Operation();

	delete l;
	delete com;
} 
