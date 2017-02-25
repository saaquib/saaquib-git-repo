#include<stdio.h>
//const char c[10] = "file.c";
int main(int argc, char *argv[])
{
	FILE *fp;
	char ch;
	fp = fopen( argv[1],"r");
		if(fp == NULL)
			printf("file doesnt exist");
	while(ch != EOF)  {
		ch = fgetc(fp);
		if((ch >= 'A') && (ch <= 'Z'))  {
			ch = ch ^ 32;
			fseek(fp,-1,SEEK_CUR);
			fputc(ch,fp);
		}
	}
	fseek(fp,0,SEEK_SET);
	while(ch != EOF)  {
		ch = fgetc(fp);
		printf("%c",ch);
	}
	fclose(fp);
	return 0;
}
