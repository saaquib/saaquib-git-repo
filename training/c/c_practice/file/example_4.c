#include <sys/types.h>                                                          
#include <unistd.h>                                                             
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include<stdio.h>                                                               
#include<stdlib.h>                                                              
#include<string.h>                                                              
#define MAX 32 
int main()
{
	int fd;
	fd = open("paper5.txt",O_CREAT|O_WRONLY|O_RDONLY,0666);
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d",a,b);
	fscanf(fd,"%d%d",a,b);
	return 0;
}

