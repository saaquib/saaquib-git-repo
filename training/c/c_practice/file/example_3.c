#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 32
int main(int argc, char *argv[])
{
	FILE *fp;
	char *str;
	str = (char*)malloc(MAX);
	fgets(str,MAX,stdin);
	fp = fopen(argv[1],"w+");
	fwrite(str,MAX,1,fp);
	fclose(fp);
	return 0;
}
