#include"header.h"

void deque(void)
{
	int dequed;
	if(((rear - 1) == -1) || ((front - 1) >= LIMIT))
		printf("\nQueue is empty");
	else  {
		dequed = queue[front];
		front++;
		printf("\nElement dequed is : %d ",dequed);
	}
}
