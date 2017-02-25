#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <sys/stat.h>
#include <mqueue.h>
#define SUCCESS 1
#define MAX 32

int main (void) {

	mqd_t mqdes;
	struct mq_attr *attr;
//	char *name;
	char *send;
	char *receive;
//	name = (char *) malloc (sizeof (char) * MAX);
	send = (char *) malloc (sizeof (char) * MAX);
//	name = "/saaq";

	if ((mqdes = mq_open ("/saaq", O_CREAT | O_RDWR, 0666, NULL)) == -1) {
		printf ("mq_open error\n");
	}
	while (SUCCESS) {

		printf("tom : ");	
		if (fgets (send, MAX, stdin) == NULL) {
			printf ("fgets error\n");
		}
		if (!strcmp (send, "bye\n")) {
			break;
		}
	
		if (mq_send (mqdes, send, MAX, 0) == -1) {
			printf ("mq_Send error\n");
		}
		mq_getattr (mqdes, attr);
	    receive = (char *) malloc (sizeof (char) * attr->mq_msgsize + 1);

    	if (mq_receive (mqdes, receive, attr->mq_msgsize + 1, 0) == -1) {
	        printf ("mq_receive error\n");
    	}
		printf ("jerry : %s\n", receive);
//  	  write (STDOUT_FILENO, string, attr->mq_msgsize + 1);
	}	
	mq_close (mqdes);
	return 0;
}

	
	
	
	
