#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <sys/types.h>
#include <mqueue.h>

#define SUCCESS 1
#define MAX 32

int main (void) {

	struct mq_attr *attr;
	mqd_t mqdes;
	char *send;
	char *receive;
	send = (char *) malloc (sizeof (char) * MAX);
	
	if ((mqdes = mq_open ("/saaq", O_RDWR)) == -1) {
		printf ("mq_open error\n");
	}
	
	mq_getattr (mqdes, attr);
	receive = (char *) malloc (sizeof (char) * attr->mq_msgsize + 1);

	while (SUCCESS) {
		if (mq_receive (mqdes, receive, attr->mq_msgsize + 1, 0) == -1) {
			printf ("mq_receive error\n");
		}

//		write (STDOUT_FILENO, receive, attr->mq_msgsize + 1);
		printf("tom : %s\n", receive);
		printf("jerry : ");
		if (fgets (send, MAX, stdin) == NULL) {
        	printf ("fgets error\n");
	    }
		if (!strcmp (send, "bye\n")) {
			break;
		}
		
		if (mq_send (mqdes, send, MAX, 0) == -1) {
    	    printf ("mq_Send error\n");
	    }
	}
	mq_close (mqdes);
	
	return 0;
}

	
	
	
	
