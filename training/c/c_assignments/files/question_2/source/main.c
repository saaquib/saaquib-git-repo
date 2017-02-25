#include"header.h"

int main()
{
	FILE *fp;
	char buffer[MAX];

	fp = fopen(argv[1],"r+");

	if(fp == NULL)
		printf("\nfile doesnt exist");

	while(buffer != EOF)  {
		buffer = fgets(buffer,fp)
