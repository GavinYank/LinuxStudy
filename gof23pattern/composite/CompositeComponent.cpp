#include "CompositeComponent.h" 

ComponentMy::ComponentMy()
{

}

ComponentMy::~ComponentMy() 
{ 
	
}

#if 1

void ComponentMy::Add(const ComponentMy& Com)
{ 
	const ComponentMy* pCom = &Com;

	pCom = pCom;
}




ComponentMy* ComponentMy::GetChild(int index) 
{ 
	index = index;
	
	return 0;
} 
void ComponentMy::Remove(const ComponentMy& com)
{ 
	const ComponentMy* pCom = &com;

	pCom = pCom;
}
#endif
//����Ƭ��2��Component.cpp 
//Component.cpp