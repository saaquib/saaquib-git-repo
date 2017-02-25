#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 32
int main()
{
	char *str;
	char buffer[MAX] = "ka ka ka saa aaiiii" ;
	str = (char*)malloc(MAX);
	FILE *fp;
	fp = fopen("practice.txt","r+");
	if(fp == NULL) 
		perror("error in opening a file");
	else printf("\nhurrayyyyyyyyyy!!!!!!!!file created successfully");
	fprintf(fp,"%s","wowwwwwwwwwwwwwwwwwww");
/*	rewind(fp);
	if((fscanf(fp,"%d", str) == EOF) && (fscanf(fp,"%d", str)))
		perror("error in reading or type conversion");
	printf("%s\n",str);*/
	rewind(fp);
	fwrite(buffer,strlen(buffer) - 1,1,fp);
	printf("%s",buffer);
	fclose(fp);
	return 0;
}
