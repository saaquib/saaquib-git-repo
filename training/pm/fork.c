#include <stdio.h>

int main (void) {
	int pid;
	
	printf("\n<-----PARENT----->");
	printf("\nParent PID : %d ", getpid());
	printf("\n<---------->");
	
	pid = fork ();
	
	printf("\nAfter fork PID : %d ", getpid());
	printf("\nReturn value of pid in Parent : %d ", pid);
	
	if (pid == 0) {
		printf("\n<-----In Child----->");
		printf("\nChild PID : %d ", getpid());
		printf("\nChild PPID ( Parent PID ) : %d ", getppid());
		printf("\nReturn value of pid in Child : %d ", pid);
		printf("\nExiting Child");
	}
		
	//wait ();	
	getchar ();
	if (pid > 0) {
		printf("\n<-----In Parent----->");
		printf("\nExiting Parent");
	}
	return 0;
}
