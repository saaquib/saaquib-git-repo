#include"header.h"

void rev_display(void)
{
	int i;
	NODE *traverse;
	traverse = tail;
	while(traverse->prev != NULL)
	{
		printf("%d\t",traverse->data);
		traverse = traverse->prev;
	}
	printf("%d\t",traverse->data);
}
