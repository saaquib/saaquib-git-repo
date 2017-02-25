#include<stdio.h>
#include<string.h>
#define MAX 32

int add1(int,int);
int sub1(int,int);
int mul1(int,int);
int div1(int,int);
int is_valid(char s[]);
int str_len(char *ch);

int (*fptr)(int,int);



