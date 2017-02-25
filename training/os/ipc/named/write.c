#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX 32

int main (void) {
	int fd;
	char *path;
	char *string;
	int status;
	path = (char *) malloc ( sizeof(char) * MAX );
	string = (char *) malloc ( sizeof(char) * MAX );

	path = "/home/saaquibh/saaq";

	status = mkfifo ( path, 0666 );
	if (status != 0 ) {
		printf ("mkfifo error \n");
	}

	fd = open (path , O_WRONLY); 
	if (fgets (string, MAX, stdin) == NULL) {
		printf ("fgets error\n");
	}
	write (fd , string, MAX);
	close (fd);
	unlink ("/home/saaquibh/saaq");

	return 0;
}
