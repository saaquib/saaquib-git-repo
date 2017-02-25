#define _GNU_SOURCE
#include "error.h"
#include<sys/types.h>
#include<sys/syscall.h>
#include <fcntl.h>

void *thread_fun(void *arg)
{
	pthread_attr_t attr;
	pthread_attr_t *attrp;
	struct sched_param prio;

	prio.sched_priority = 94;

	int p;

	attrp = NULL;

	attrp = &attr;
	p = pthread_attr_init(&attr);
	
	if(p != 0)
		errno_abort("pthread_attr_init");


/*	p = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(p != 0)
		printf("pjhthraed is failed\n");
*/	p = pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
	if(p != 0)
		errno_abort("setinheritsched");

	
	p = pthread_setschedparam(pthread_self(), SCHED_RR, &prio);
	if(p != 0)
		errno_abort("setschedparam");

/*	pthread_attr_t gattr;
	struct sched_param prio;
	
	int s;
	int i;
	
	s = pthread_getattr_np(pthread_self(), &gattr);

	s = pthread_getschedparam(pthread_self(), &i, &prio);
	if(i == SCHED_RR)
		printf("sched_rr\n");
*/	printf("priority %d\n",prio.sched_priority);
	ioctl(((int *)arg), syscall(SYS_gettid),3);

	return NULL;
}

int main()
{
	pthread_t thr;
	int fd;
	int pid;
	int status;                                                         
	fd = open("/dev/myChar", O_RDWR);
	pthread_t th_id;                                                    

	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("pid:%d\n",getpid());
	
	
	status = pthread_create(&thr, NULL, thread_fun, fd);
	if(status != 0)
		printf("pthraoued is failed\n");

	ioctl(fd, syscall(SYS_gettid),3);
	pthread_exit(NULL);
	return 0;
}
