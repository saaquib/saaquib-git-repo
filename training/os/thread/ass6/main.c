#include "errors.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <signal.h>
#include <math.h>
#define MAX 32


typedef struct member {
	int second;
	char name[MAX]; 
	struct member *next;
} MEM;

struct mutex_lock {
	pthread_mutex_t lock;
	MEM *first;
} head = {
	.lock = PTHREAD_MUTEX_INITIALIZER
};

void *thread_function (void *p) {
	int status;
	int sleep_time;
	char message[MAX];

	while (1) {
		while ( head.first == NULL ) {
			sleep (1);
		} 
		status = pthread_mutex_lock (&head.lock);
		if (status != 0) {
			errno_abort ("Lock failed");
		}	

		sleep_time = head.first->second;
		strcpy (message, head.first->name);	
		head.first = head.first -> next;

		status = pthread_mutex_unlock (&head.lock);
		if (status != 0) {
			errno_abort ("Lock failed");
		}	
		sleep (sleep_time );
		printf("(%d) : %s\n",sleep_time, message);
	}
    return NULL;
}

int main (void) {
	char line[MAX];
    int status;
    pthread_t th_id;
	MEM *node;
	MEM *traverse = NULL;
	MEM *previous = NULL;
	
	status = pthread_create (&th_id, NULL, thread_function, NULL);
	if (status != 0) {
		errno_abort ("pthread_create failed..\n");
    }				

	while(1) {
		
		printf ("alarm...");
		if (NULL ==(fgets(line, sizeof(line), stdin))) {
			errno_abort ("fgets failed..\n");
			exit (1);
		}	
		
		node = (MEM *) malloc (sizeof (MEM));
		if (sscanf(line, "%d %4[^\n]", &(node -> second), node -> name) < 2) {
				errno_abort ("bad command\n");
//				continue;
		}	
		
		status = pthread_mutex_lock (&head.lock);
		if (status != 0) {
			errno_abort ("Lock failed");
		}	
		// insert node in a linked list .. insert_node()
#if 0
		if ( head.first == NULL) {
			node -> next = NULL;
			head.first = node;
		} else {
			node -> next = head.first;
			head.first = node;
    	}
#endif
#if 1
		if ( head.first == NULL ) {
			node -> next = NULL;
			head.first = node;
		} else {
			traverse = head.first;
			previous = NULL;
			while ( (traverse -> second <= node -> second) && ( traverse != NULL) ) {
				previous = traverse;
				traverse = traverse -> next;
			}
			if ( previous != NULL ) {
				previous -> next = node;
				node -> next = traverse; 
			} else {
				node -> next = head.first;
				head.first = node;
			}	
		}				
#endif

		status = pthread_mutex_unlock (&head.lock);
		if (status != 0) {
			errno_abort ("UnLock failed");
		}	
	} // End of while (...)

	pthread_exit (NULL);

    return 0;
}
