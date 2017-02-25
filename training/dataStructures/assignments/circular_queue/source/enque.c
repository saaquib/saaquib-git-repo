#include"header.h"

void enque(int element)
{
	if(count >= LIMIT)
		printf("\nQueue is full");
	else  {
		queue[rear] = element;
		rear = ((rear + 1) % LIMIT);
		count++;
	}
}

