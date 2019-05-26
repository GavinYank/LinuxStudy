#ifndef _COMPOSITE_H_ 
#define _COMPOSITE_H_ 
#include"CompositeComponent.h" 
#include<vector>
using namespace std; 
class Composite:public ComponentMy 
{ 
	public: 
		Composite(); 
		~Composite(); 

		void Operation();
		void Add(ComponentMy* com); 
		void Remove(ComponentMy* com); 
		ComponentMy* GetChild(int index);
	protected: 
	private: 
		vector<ComponentMy*> comVec; 
}; 
#endif //~_COMPOSITE_H_