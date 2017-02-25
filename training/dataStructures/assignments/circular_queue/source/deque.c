#include"header.h"

void deque(void)
{
	int dequed;
	if(count == 0)
		printf("\nQueue is empty");
	else  {
		dequed = queue[front];
		front = ((front + 1) % LIMIT);
		count--;
		printf("\nElement dequed is : %d ",dequed);
	}
}
