
#include <stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd123 {
char *pw_name; /* 登录名称 */
char *pw_passwd; /* 登录口令 */
uid_t pw_uid; /* 用户 ID */
gid_t pw_gid; /* 用户组 ID */
char *pw_gecos; /* 用户的真名  */
char *pw_dir; /* 用户的目录 */
char *pw_shell; /* 用户的 SHELL */
};

void OutputPasswd(const struct passwd* p)
{
	printf("name: %s\n", p->pw_name);
	printf("passwd: %s\n", p->pw_passwd);
	printf("uid_t: %ld\n", (long int)p->pw_uid);
	printf("gid_t: %ld\n", (long int)p->pw_gid);
	printf("gecos: %s\n", p->pw_gecos);
	printf("dir: %s\n", p->pw_dir);
	printf("shell: %s\n", p->pw_shell);
}


int main12(int argc, char **argv);

void MyProcessMain(void)
{
	uid_t my_uid = getuid();
	struct passwd* my_info = getpwuid(my_uid);
	OutputPasswd(my_info);

	printf("Process ID: 	%ld\n", (long int)getpid());
	printf("Parent ID:	%ld\n", (long int)getppid());
	printf("User ID:	%ld\n", (long int)getuid());
	printf("Effective User ID:	%ld\n", (long int)geteuid());
	printf("Group ID:	%ld\n", (long int)getgid());
	printf("Effective Group ID:	%ld\n", (long int)getegid());

	//main12(0, NULL);
}


/* tcut.h: Tiny C Unit Test framework*/
#ifndef _TCUT_H
#define _TCUT_H

#define tcut_assert(what, test) do { if (!(test)) return what; } while (0)
#define tcut_run_test(test) do { char *what = test(); nr_tests++; if (what) return what; } while (0)
extern int nr_tests;

#endif

#include <stdio.h>
//#include "tcut.h"

int nr_tests = 0;

int foo = 7;
int bar = 4;

static char * test_foo()
{
    tcut_assert("error, foo != 7", foo == 7);
    return 0;
}

static char * test_bar()
{
    tcut_assert("error, bar != 5", bar == 5);
    return 0;
}

static char * all_tests() 
{
    tcut_run_test(test_foo);
    tcut_run_test(test_bar);
    return 0;
}

int main12(int argc, char **argv)
{
	char *result = all_tests();

	argc = argc;
	argv = argv;
	
	if (result != 0) {
	    printf("%s\n", result);
	}
	else {
	    printf("ALL TESTS PASSED\n");
	}

	printf("Tests run: %d\n", nr_tests);

	return result != 0;
}





