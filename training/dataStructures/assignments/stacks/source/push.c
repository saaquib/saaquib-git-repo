#include"header.h"

void push(int element)
{
	if(top >= LIMIT)
		printf("Stack is full \n");
	else  {
		stack[top++] = element;
	}
}
