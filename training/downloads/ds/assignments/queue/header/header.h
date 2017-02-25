#include <stdio.h>
#include <stdlib.h>

#define MAX 64

int queue[MAX];
int front;
int rear;

void enqueue(int);
int dequeue();
void display();
