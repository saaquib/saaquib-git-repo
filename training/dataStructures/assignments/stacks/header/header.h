#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Macro definitions */
#define LIMIT 10
#define MAX 32

/*Global Variables */
int top;
int stack[LIMIT];

/*Functions declaration */
void push(int);
void pop();
void display(void);
void rem_ent(char *);
int str_len(char *);
int is_valid(char *s);
