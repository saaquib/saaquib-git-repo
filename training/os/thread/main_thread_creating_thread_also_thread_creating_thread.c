#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>

void *thread_function2 (void *p) {
    printf("<-----Inside thread2 funtion----->\n");
    printf("Thread2 PID :  %d\n",getpid ());
    printf("Thread2's Thread ID :  %ld\n",syscall (SYS_gettid));
    
	printf("<-----exit thread2----->\n");
	return NULL;
}

void *thread_function1 (void *p) {
    int parent_status2;
    pthread_t th_id2;

    printf("<-----Inside thread1 funtion----->\n");
    printf("Thread1 PID :  %d\n",getpid ());
    printf("Thread1's Thread ID :  %ld\n",syscall (SYS_gettid));
    //pid_t thread_pid1 = fork ();

    parent_status2 = pthread_create (&th_id2, NULL, thread_function2, NULL);

    if (parent_status2 != 0) {
        printf("Thread1 creation failed : %s\n", strerror (parent_status2));
    }
	
/*	if ( thread_pid1 == 0 ) {
		printf("<-----Thread function 1 child -----> \n"); 
		printf("getpid :\t%u \n", getpid ());
    	printf("Thread ID :\t%ld\n",syscall (SYS_gettid));
		printf("getppid :\t%u \n", getppid ());
		printf("\n");
	} else {
		printf("<-----Thread function 1 parent -----> \n"); 
		printf("getpid :\t%u \n", getpid ());
    	printf("Thread ID :\t%ld\n",syscall (SYS_gettid));
		printf("getppid :\t%u \n", getppid ());
		printf("\n");
	}
		
  */  
    pthread_exit (NULL);
	printf("<-----exit thread1----->\n");
	return NULL;
}

int a = 4;

int main (void) {
    int parent_status1;
    pthread_t th_id1;
	parent_status1 = pthread_create (&th_id1, NULL, thread_function1, NULL);
    pthread_t th_id2;

    printf("<-----Inside Parent------> \n");
    printf("Parent PID :  %d\n",getpid ());
    printf("Parent's Thread ID :  %ld\n",syscall (SYS_gettid));

    printf ("a : %d\n",a);
    pthread_exit (NULL);
	printf("<-----exit parent----->\n");
    return 0;
}
