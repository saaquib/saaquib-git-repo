#include"header.h"

void display(void)
{
	int i;
	for(i = front + 1;i <= rear; i++)
		printf("\nqueue[%d] = %d ",i - 1,queue[i - 1]);
}
