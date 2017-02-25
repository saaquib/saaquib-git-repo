#include"header.h"

void delete_at_end(void)
{
	NODE *traverse;
	NODE *prev;
	traverse = head;
	if (head == NULL) {
		printf("\nList is empty");
	} else if (count == 1) {
		delete_at_begining();
	}
	else {
		while(traverse->link != NULL)  {
			prev = traverse;
			traverse = traverse->link;
		}
		prev->link = NULL;
		free(traverse);
		count--;
	}
}
