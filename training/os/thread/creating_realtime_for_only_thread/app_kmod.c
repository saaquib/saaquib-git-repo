#define _GNU_SOURCE
#include "errors.h"
#include<sys/types.h>
#include<sys/syscall.h>
#include <fcntl.h>

void *thread_fun(void *arg)
{
	int p;
	int policy;
	struct sched_param prio;
	prio.sched_priority = 94;
	
	p = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(p != 0)
		errno_abort("setschedparam");

	p = pthread_getschedparam(pthread_self(), &policy, &prio);
	if(p != 0)
		errno_abort("setschedparam");

	if ( policy == SCHED_RR) {
		printf ("sched_rr\n");
	} else if ( policy == SCHED_FIFO) {
		printf ("sched_fifo\n");
	} else if ( policy == SCHED_OTHER) {
		printf ("sched_other\n");
	}

	printf("thread priority %d\n",prio.sched_priority);
	ioctl(((int *)arg), syscall(SYS_gettid),3);

	return NULL;
}

int main()
{
	int fd;
	int pid;
	int status;                                                     	pthread_t thr;
	pthread_t th_id;                                                    
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("pid:%d\n",getpid());
	
	status = pthread_create(&thr, NULL, thread_fun, fd);
	if(status != 0)
		printf("pthread is failed\n");

	ioctl(fd, syscall(SYS_gettid),3);
	pthread_exit(NULL);
	return 0;
}
