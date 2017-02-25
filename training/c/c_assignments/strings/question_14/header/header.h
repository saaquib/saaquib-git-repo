#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 32

extern int str_len(char *);

extern int is_valid(char s[]);

extern void is_mem_valid(char *);

void rem_ent(char *);

char* rem_sub_str(char*, char*);
