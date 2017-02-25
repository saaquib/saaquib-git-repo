#include"header.h"

void display(void)
{
	int i;
	NODE *traverse;
	traverse = head;
	if (head == NULL) {
		printf("\n List is empty");
	}
	else {
		while(traverse->link != NULL)
		{
			printf("%d\t",traverse->data);
			traverse = traverse->link;
		}
		printf("%d\t",traverse->data);
	}
}
