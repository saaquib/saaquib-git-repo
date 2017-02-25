#include"header.h"

void display(void)
{
	int i;
	NODE *traverse;
	traverse = head;
	while(traverse->link != NULL)
	{
		printf("%d\t",traverse->data);
		traverse = traverse->link;
	}
	printf("%d\t",traverse->data);
}
