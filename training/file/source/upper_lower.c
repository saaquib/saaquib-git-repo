#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	char ch;
	fp = fopen("text.txt","r+");
	
	if(fp == NULL)
		printf("\nNo file to open");
	
	while(ch != EOF)  {
		ch = fgetc(fp);
		if((ch >= 'A') && (ch <= 'Z')){
			ch = ch ^ 32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
	}
	/*fseek(fp,0,SEEK_SET);
	
	while(ch != EOF)  {
		ch = fgetc(fp);
		 putc(ch,stdout);
	}*/
	fclose(fp);
	return 0;
}
		
	
