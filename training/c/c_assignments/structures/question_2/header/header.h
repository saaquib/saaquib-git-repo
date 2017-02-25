#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 32

extern int is_valid(char s[]);

void rem_ent(char *);

extern int str_len(char *);

union sample
{
	int a:5;
	int b:10;
	int c:5;
	int d:21;
	int e;
};
