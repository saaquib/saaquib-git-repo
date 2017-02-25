#include"header.h"

int main()
{
	FILE *fp;
	char ch;
	fp = fopen("text.txt","r+");
	
	if(fp == NULL)
		printf("\nNo file to open");
	
	while((ch = fgetc(fp)) != EOF)  {
		if((ch >= 'A') && (ch <= 'Z')){
			ch = ch ^ 32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
	}
	fseek(fp,0,SEEK_SET);
	while((ch = fgetc(fp)) != EOF)
		printf("%c",ch);
	fclose(fp);
	return 0;
}
		
	
