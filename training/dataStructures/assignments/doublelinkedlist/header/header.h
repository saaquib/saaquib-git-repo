#include<stdio.h>
#include<stdlib.h>

#define MAX 32

typedef struct node  {
	int data;
	struct node *next;
	struct node *prev;
} NODE; 

NODE* create(void);

void insert_at_begining(void);

void delete_at_begining(void);

void insert_at_end(void);

void delete_at_end(void);

void insert_at_given_position(int);

void delete_at_given_position(int);

void insert_before_given_pos(int);

void insert_after_given_pos(int);

void insert_before_given_num(int);

void insert_after_given_num(int);

void delete_after_given_num(int);

void delete_given_num(int);

void insert_at_middle(void);

void insert_at_penultinate(void);

void display(void);

void rev_display(void);

struct node *head;
struct node *temp;
struct node *tail;

int count;
