#include <stdio.h>
#include <fcntl.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/syscall.h>

int *thread_create(void *p){                                            
    printf("------thread function----\n");                              
//    printf("a : %d\n",a);                                               //   a = a + 20;                                                         
//    printf("a of thread: %d\n",a);                                      
    printf("tgid  of thread : %d\n ", getpid());                        
    printf("tid  of thread : %d\n ",syscall(SYS_gettid));               
    printf("-------------------\n");
	ioctl(((int *)p), syscall(SYS_gettid),3);
    getchar();                                                          
    return 0;                                                           
}               

int main( void )
{
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
	

/*	getchar();
	pid = vfork();
	getchar();
	if(pid > 0){
		ioctl(fd,getpid(),3);
	}else if(pid == 0){
		ioctl(fd,getpid(),3);
		exit(1);
	}else{
		printf("failed\n");
	}
*/

                                                                        
    status = pthread_create(&th_id, NULL,thread_create,fd);           
    printf("-------main thread or process---\n");
/*    printf("value of a : %d\n", a);                                     
    a = a + 30;                                                         
  */  printf("pid of  group leader: %d ", getpid());                      
                                                                        
    if(status != NULL){                                                 
        printf("pthread failed: %s\n",strerror(status));                
    }                                                                   
	ioctl(fd, syscall(SYS_gettid),3);
        printf("thread_id :%p\n",th_id);                                
        printf("-----------------------------\n");                  
        pthread_exit(NULL);                           
	close(fd);

	return 0;
}
