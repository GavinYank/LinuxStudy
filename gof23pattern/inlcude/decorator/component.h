#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component
{
	public:
		virtual void Operation(void) = 0;
};


class DlistComponent: public Component
{
	public:
		virtual void Operation(void);
		virtual ~DlistComponent(void);
};


#endif



















