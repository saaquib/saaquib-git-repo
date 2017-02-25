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
	struct member *next;
} MEM;

typedef struct my_struct_tag {
	pthread_mutex_t mutex;
	MEM member;
} my_struct_t;

MEM *head = NULL;
MEM *traverse;

void *thread_function1 (void *p) {
//sleep (5);
	MEM *num;
	num = (MEM *)p;
	sleep (num->second);
	printf("(%d) : %s",num->second, num->name);
  //  printf("%s\n",(MEM *)p.name);
//    getchar ();
    return NULL;
}

void *thread_function1 (void *p) {
	int status;
	pthread_t th_id2;
	
    if (status != 0) {
		errno_abort("pthread_create failed..\n");
	}
	
int a = 4;
int main (void) {
	char line[MAX];
    int status;
    pthread_t th_id;
	MEM *node;
	my_struct_t *data;
	
	node = (MEM *) malloc (sizeof (MEM));
	data = (my_struct_t *) malloc (sizeof (my_struct_t));
	
	if (data == NULL) {
		errno_abort ("Alloc structure");

	status = pthread_mutex_init ( &data -> mutex, NULL);
	
	if (status != 0) {
		err_abort (status, "Init mutex" );
	}	

	printf("Enter the time in seconds and message: ");

	while(1) {
		printf ("alaram...");
		if (NULL ==(fgets(line, sizeof(line), stdin))) {
			errno_abort("fgets failed..\n");
			exit (0);
		}	
		
		status = pthread_mutex_lock (&data -> mutex);
		if (status != 0) {
			err_abort (status, "Lock failed" );
		}	
		
		if (sscanf(line, "%d %4[^\n]", node -> second, node -> name) < 2) {
				errno_abort("bad command\n");
		}	
	
		if ( head == NULL) {
			head = node;
		} else {
			traverse = head;
			while ( traverse -> second < node -> second ) {
				traverse = traverse -> next;
			}

		status = pthread_create (&th_id, NULL, thread_function2, &node);
    		if (status != 0) {
				errno_abort("pthread_create failed..\n");
	    	}
		
    }
	pthread_exit (NULL);

    return 0;
}
