#include"header.h"

void delete_after_given_position(int pos)
{
	NODE *traverse;
	NODE *prev;	
	traverse = head;
	if (count == 0) {
		printf("\n List is empty");
		return;
	} else if (count == 1) {
		printf("\n Only one element in the list");
		return;
	} else if ((pos - 1) >= count) {
		printf("\n No such position");
		printf("\n Max position is : %d ",count - 2);
		return;
	}
	else {
		pos++;
		while(pos--) {
			prev = traverse;
			traverse = traverse->link;
		}
		prev->link = traverse->link;
		free(traverse);
		count--;
	}
}
