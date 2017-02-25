#include <stdio.h>
#include <fcntl.h>

int main()
{
	
	int fd;
	
	fd = open("/dev/myChar",O_RDWR);

	if ( fd < 0 )
		perror("Unable to open the device\n");
	else
	printf("File opened successfully %d\n",fd);

//	int pid = fork();
//	if ( pid == 0) {
	ioctl(fd,getpid(),2);
	close(fd);
	printf("%d",getpid());
	return 0;
}
	

