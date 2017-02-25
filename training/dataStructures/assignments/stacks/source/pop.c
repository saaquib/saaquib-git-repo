#include"header.h"

void pop()
{
	int poped;
	if(top - 1 < 0)
		printf("Stack is empty\n");
	else  {
		poped = stack[top - 1];
		top--;
		printf("\nElement poped is : %d ",poped);
	}
}
