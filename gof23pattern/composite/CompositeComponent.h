#ifndef __COMPOSITE_COMPONENT_H__ 
#define __COMPOSITE_COMPONENT_H__ 
class ComponentMy
{ 
	public: 
		ComponentMy(); 
		virtual ~ComponentMy(); 

		virtual void Operation()= 0; 
		virtual void Add(const ComponentMy& com);
		virtual void Remove(const ComponentMy& com); 
		virtual ComponentMy* GetChild(int index); 
	protected: 
	private: 
}; 
#endif //~_COMPONENT_H_ 