#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 32

int main (void) {
	int fd;
    char *buf;
    char *path;
    char c;

	buf = (char *) malloc (sizeof (char) * MAX);
	path = (char *) malloc (sizeof (char) * MAX);
	path = "/home/saaquibh/saaq";
	
    fd = open(path, O_RDONLY);
    printf("read file\n");

    read (fd, buf, MAX);
    printf ("named output : %s\n", buf);

    close (fd);

    return 0;
}

