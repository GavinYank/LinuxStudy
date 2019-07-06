#include <stdio.h>
#include "main.h"
#include "common.h"
extern void FileMain(void);
void CommonMacroTest(void);
void DListMain(void);
void Gof23PatternMain(void);
void MyProcessMain(void);
extern void process_test(void);
extern void pthread_main(void);

int main(int argc, char* argv[])
{
	char** p = argv;

	p = p;
	argc = argc;

	//FileMain();
	//DListMain();
	Gof23PatternMain();
	//MyProcessMain();	
	printf("Hello World2\n");
	//printf("Hello World31546\n");
	//process_test();
	//pthread_main();
	
	//#error
	return (0);
}

