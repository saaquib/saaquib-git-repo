#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 10
#define MAX 64

int main (void) {
	int shmdes;
	int status;
	int *memaddr;
	int arr[SIZE];
	int track;
	
	if ((shmdes = shm_open ("/saaq", O_CREAT | O_RDWR, 0666)) == -1) {
		printf("shm_open error\n");
	}

	status = ftruncate (shmdes, 4096);
	if (status == -1) {
		printf("ftruncate error\n");
	}

	memaddr = (int *) mmap (NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, shmdes, 0);

	for (track = 1; track <= 10; track++) {
		arr[track - 1] = track;
	}
	
	memaddr = memcpy (memaddr, arr, sizeof (arr));
	close (shmdes);
	return 0;
}
	
	
