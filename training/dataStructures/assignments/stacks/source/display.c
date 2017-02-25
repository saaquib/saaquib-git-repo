#include"header.h"

void display(void)
{
	int i;
	for(i = top;i > 0; i--)
		printf("\nstack[%d] = %d ",i - 1,stack[i - 1]);
}
