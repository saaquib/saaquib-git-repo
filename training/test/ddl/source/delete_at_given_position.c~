#include"header.h"

void delete_at_middle(void)
{
	NODE *previous;
	NODE *traverse;
	int pos = (count / 2);
	traverse = head;
	if (count == 0) {                                                           
	        printf("\n List is empty");
	} else if (pos >= count) {
		printf("\n No such position");                                          
	        printf("\n Max position is : %d ",count - 1);
	} else if(pos == 0) {
		delete_at_begining();
	}
	else {
		while(pos--) {
			previous = traverse;
			traverse = traverse->next;
		}
		previous->next = traverse->next;
		traverse -> next -> prev = previous;
		free(traverse);
		count--;
	}
}
