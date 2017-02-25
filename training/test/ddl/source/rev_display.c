#include"header.h"

void rev_display(void)
{
	int i;
	NODE *traverse;
	traverse = tail;
	while(traverse->prev != NULL)
	{
		printf("%s\t",traverse->data);
		traverse = traverse->prev;
	}
	printf("%s\t",traverse->data);
}
