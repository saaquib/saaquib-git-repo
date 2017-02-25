#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

void *thread_function (void *p) {
	printf("Inside thread funtion\n");
	printf("Thread PID :  %d\n",getpid ());
	printf("Thread's Thread ID :  %ld\n",syscall (SYS_gettid));
	getchar ();
	return NULL;
}

int a = 4;

int main (void) {
	int status;
	pthread_t th_id;

	status = pthread_create (&th_id, NULL, thread_function, NULL);
	if (status != 0) {
		printf("Thread creation failed : %s\n", strerror (status));
	}
	
	printf("Inside Parent \n");
	printf("Parent PID :  %d\n",getpid ());
	printf("Parent's Thread ID :  %ld\n",syscall (SYS_gettid));
	
	getchar ();
	printf ("a : %d\n",a);
	pthread_exit (NULL);
	return 0;
}
