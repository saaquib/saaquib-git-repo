#include <stdio.h>
#include <fcntl.h>

int a = 10;
int main( void )
{
	int fd;

	fd = open("/dev/myChar", O_RDWR);


	if (fd < 0)
		perror("Unable to open the Device");
	else
		printf("File Opened Successfully %d\n", fd);
	printf("pid:%d\n",getpid());
	printf ("a = %d before ioctl\n", a);
	ioctl(fd, getpid(), &a);
	printf ("a = %d after ioctl\n", a);
	close(fd);

	return 0;
}
