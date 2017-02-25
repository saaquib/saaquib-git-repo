#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include<semaphore.h>

#define SUCCESS 1
#define SIZE 10
#define MAX 64

int main (void) {
	int shmdes;
	int status;
	int *memaddr;
	int arr[SIZE];
	int track;
	sem_t *sem;
	
	if ((shmdes = shm_open ("/saaq", O_CREAT | O_RDWR, 0666)) == -1) {
		printf("shm_open error\n");
	}
	
	sem = sem_open ("/saaqsem", O_CREAT, 0666, 1);
	if (sem == SEM_FAILED) {
		printf("sem_open error\n");
	}

	status = ftruncate (shmdes, 4096);
	if (status == -1) {
		printf("ftruncate error\n");
	}

	memaddr = (int *) mmap (NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shmdes, 0);

	while (SUCCESS)	{
		printf ("enter arr[0] value :");
		scanf ("%d", &arr[0]);
		*memaddr = arr[0];

		if (*memaddr == 0) {
			for (track = 1; track <= 10; track++) {
				arr[track] = 10;
			}

			memcpy (memaddr, arr, sizeof (arr));

			for (track = 0; track < 10; track++) {
                printf("*(memaddr + %d) = %d\n", track, *(memaddr + track));    
            }

		} else {
			memcpy (memaddr, arr, 4);
			printf("*(memaddr) = %d\n",*memaddr);
		}
	}
	close (shmdes);
	return 0;
}
	
	
