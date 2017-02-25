#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>

#define SIZE 10
#define MAX 64

int main (void) {
	int shmdes;
	int status;
	int *memaddr;
	int buf[MAX];
	int track;
	sem_t *sem;
	
	if ((shmdes = shm_open ("/saaq", O_RDWR, 0666)) == -1) {
		printf("shm_open error\n");
	}

	sem = sem_open ("/saaqsem", O_CREAT, 0666, 1);
	if (sem == SEM_FAILED) {
		printf("sem_open error\n");
	}
	
	memaddr = (int *) mmap (NULL, 40, PROT_READ | PROT_WRITE, MAP_SHARED, shmdes, 0x0);
	if(memaddr == MAP_FAILED) {
			printf ("mmap error\n");
	}

	status = sem_wait (sem);
	if (status == -1) {
		printf("sem_wait error\n");
	}

	memcpy (buf, memaddr, 40);

	for (track = 1; track <= 10; track++) { 
 	   printf("buf [%d] = %d\n", track - 1, buf[track - 1]);
	}

	status = sem_post (sem);  
    if (status == -1) {
        printf("sem_post error\n");
    }
	
	status = sem_wait (sem);
	if (status == -1) {
		printf("sem_wait error\n");
	}

	memset (memaddr, 0, 40);
	
	status = sem_post (sem);  
    if (status == -1) {
        printf("sem_post error\n");
    }
	close (shmdes);
	shm_unlink ("/saaq");
	return 0;
}
	
	
