#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#define MAX 32
typedef struct member {
	int second;
	char name[MAX]; 
} MEM;

void *thread_function (void *p) {
//sleep (5);
	MEM *num;
	num = (MEM *)p;
	sleep (num->second);
	printf("(%d) : %s",num->second, num->name);
  //  printf("%s\n",(MEM *)p.name);
//    getchar ();
    return NULL;
}

int a = 4;
int main (void) {
//	while (1) {
    int status;
	struct member m1;
    pthread_t th_id;
	printf("Enter the time in seconds and message: ");
	scanf ("%d %s", &m1.second,&m1.name );
	
    status = pthread_create (&th_id, NULL, thread_function, &m1);
    if (status != 0) {
        printf("Thread creation failed : %s\n", strerror (status));
    }
    getchar ();
//	}
    pthread_exit (NULL);

    return 0;
}
