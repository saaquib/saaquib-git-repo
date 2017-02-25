#include <stdio.h>
#include <stdlib.h>
#define MAX 32
typedef struct node {
	int data;
	struct node *link;
} NODE;

void delete (void);

NODE *head;
NODE *temp;
int count;

