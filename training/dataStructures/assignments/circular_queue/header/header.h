#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LIMIT 5

#define MAX 32

int count;

int front;

int rear;

void enque(int);

void deque(void);

void display(void);

void rem_ent(char *);

int str_len(char *);

int is_valid(char *s);

int queue[LIMIT];
