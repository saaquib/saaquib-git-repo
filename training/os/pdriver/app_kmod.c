#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int fd;
	fd = open ("/dev/myChar", O_RDWR);
	if(fd < 0)
		perror("Unable to oprn the device");
	else
		printf("File opened successfully %d\n",fd);
	ioctl(fd, getpid(), 4);
	close(fd);
	return 0;
}
