#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2
int main()
{
	FILE *fp1, *fp2;
	int buf[MAX] = {10, 15};
	fp1 = fopen("pap1.txt","w+");
	fp2 = fopen("pap2.txt","w+");
	fprintf(fp2,"%d%d",10,15);
	fwrite(buf,MAX,2,fp1);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
