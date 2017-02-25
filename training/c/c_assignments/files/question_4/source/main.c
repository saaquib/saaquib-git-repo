#include"header.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	int count = 0;
	fp = fopen(argv[1],"r+");
	
	if(fp == NULL)
		printf("\nNo file to open");
	
	while((ch =fgetc(fp)) != EOF)  {
		if((ch == '\n') || (ch == ' '))
			count++;
	}
	printf("\n Number of words are %d",count);
	fclose(fp);
	return 0;
}
		
	
