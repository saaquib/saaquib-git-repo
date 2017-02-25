#include"header.h"

void enque(int element)
{
	if(rear >= LIMIT)
		printf("\nQueue is full");
	else  {
		queue[++rear - 1] = element;
	}
}

