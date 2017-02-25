#include<stdio.h>
#include<stdlib.h>

#define MAX 32

typedef struct node  {
	int data;
	struct node *link;
} NODE; 

void create(NODE *);

NODE* insert_at_begining(void);

int search(int);

void display(void);

int is_valid(char s[]);

void rem_ent(char *str);

int str_len(char *ch);

NODE *head;
NODE *traverse;
