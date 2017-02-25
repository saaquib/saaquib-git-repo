#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 32

extern int str_len(char *);

extern int is_valid(char s[]);

extern void is_mem_valid(char *);

char* chr_addr_inst(char *, char);

void display_addr(char *);
