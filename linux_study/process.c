#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>


typedef int (*pfprocess)(void* pctx);



static int new_process(void* pctx)
{
	printf("%s %ld\n", __func__, (long int)pctx);
	printf("Process ID: 	%ld\n", (long int)getpid());

	return (0);
}
//claybox806

pid_t fork_process(pfprocess process, void* pctx)
{
	pid_t fork_ret = -1;

	if(NULL != process)
	{
		fork_ret = fork();

		if(0 == fork_ret)
		{
			_exit(process(pctx));
		}
	}

	return (fork_ret);
}

static void* my_pthread(void* arg)
{
	arg = arg;

	printf("%s arg = %d\n", __func__, *(int*)arg);

	return (NULL);
}

void pthread_main(void)
{
	pthread_t pthread_id = 10;
	int reg = 0;
	int TestArg = 12345678;

	printf("%s pthread_id 00 = %d\n", __func__, (int)pthread_id);
	reg = pthread_create(&pthread_id, NULL, my_pthread, &TestArg);	
	printf("%s pthread_id 11 = %d\n", __func__, (int)pthread_id);
	sleep(1);
	printf("%s arg = %d\n", __func__, (int)reg);
}

void process_test(void)
{	
	pid_t wait_ret = -1;
	int stat_loc = 0;
	
	printf("process_start\n");
	wait_ret = fork_process(new_process, (void*)908);
	printf("wait_ret 00:%d\n", wait_ret);
	wait_ret = wait(&stat_loc);
	printf("wait_ret 11:%d\n", wait_ret);
	printf("stat_loc:%d\n", stat_loc);
	//printf("WIFEXITED:%d\n", WIFEXITED);
	
	printf("process end\n");
}







