#include"header.h"

void display(void)
{
	int i;
	NODE *traverse;
	traverse = head;
	while(traverse->next != NULL)
	{
		printf("%s\t",traverse->data);
		traverse = traverse->next;
	}
	printf("%s\t",traverse->data);
}
