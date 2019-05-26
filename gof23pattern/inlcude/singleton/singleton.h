#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include<iostream>
using namespace std;

class Singleton 
{ 
	public: 
		static Singleton* Instance(int dLine);
		//void GetInstance(void);
		
	protected:
	//public:
		Singleton();

		
	private:
	//public:
		static Singleton* _instance; 
}; 


extern void SingletonMain(void);

#endif//~_SINGLETON_H_ 



