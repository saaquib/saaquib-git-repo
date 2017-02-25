#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <semaphore.h>

#define SUCCESS 1
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

	while (SUCCESS) {
		memcpy (buf, memaddr, 40);
		printf("Press Enter\n");	
		getchar ();
		printf("%d\n", *memaddr);
		if (*memaddr == 1) {
	
			for (track = 1; track <= 10; track++) {
				buf[track] = 20;
			}
		
			memcpy (memaddr, buf, 40);

			for (track = 0; track < 10; track++) { 
 	   			printf("*(memaddr + %d) = %d\n", track, *(memaddr + track));
			}

		} else {
			printf("*(memaddr) = %d\n",*memaddr);
		}
	}

	close (shmdes);
	shm_unlink ("/saaq");
	return 0;
}
	
	
