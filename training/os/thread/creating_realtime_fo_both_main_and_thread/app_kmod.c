#include <pthread.h>
#include "errors.h"
#include<sys/types.h>
#include<sys/syscall.h>
#include <fcntl.h>

void *thread_fun(void *arg)
{
	int s;
	int policy;
	struct sched_param prio;
	
	s = pthread_getschedparam(pthread_self(), &policy, &prio);
	
	if ( policy == SCHED_OTHER ) {
		printf ("sched_other\n");
	} else if ( policy == SCHED_RR ) {
		printf ("sched_rr\n");
	} else if ( policy == SCHED_FIFO ) {
		printf ("sched_fifo\n");
	}
	printf(" thread priority %d\n",prio.sched_priority);
	
	ioctl(*((int *)arg), syscall(SYS_gettid),3);

	return NULL;
}

int main ( void ) {
	
	int fd;
	int pid;
	int p;
	int policy;
	pthread_t thr;
	pthread_t th_id;                                              
	pthread_attr_t attr;
	struct sched_param prio;
	
	prio.sched_priority = 87;
	
	fd = open("/dev/myChar", O_RDWR);

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("pid:%d\n",getpid());

	p = pthread_attr_init(&attr);
	if(p != 0)
		errno_abort("pthread_attr_init");

/*	p = pthread_attr_setschedpolicy(&attr, SCHED_RR);
	if(p != 0)
		err_abort(p,"setsched policy");
	
	p = pthread_attr_setschedparam(&attr, &prio);
	if(p != 0)
		err_abort(p,"setschedparam");

	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		errno_abort("setinheritsched");	

*/	p = pthread_setschedparam(pthread_self (),SCHED_RR, &prio);
	if(p != 0)
		err_abort(p,"setschedparam");
	
	p = pthread_getschedparam(pthread_self(), &policy, &prio);
	if ( policy == SCHED_OTHER ) {
		printf ("sched_other\n");
	}
	printf("main thread priority %d\n",prio.sched_priority);
	
	p = pthread_create(&thr, &attr, thread_fun, &fd);
	if(p != 0)
		errno_abort("pthread_create");
	
	ioctl(fd, syscall(SYS_gettid),3);
	pthread_exit(NULL);
	return 0;
}
