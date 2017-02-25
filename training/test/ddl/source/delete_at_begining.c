#include"header.h"

void delete_at_begining(void)
{
	NODE *temp;
	temp = head;
	if (head == NULL) {
		printf("\nList is empty");
	}
	else {
		head = temp->next;
		temp->next->prev = NULL;
		
		free(temp);
		count--;
	}
}
