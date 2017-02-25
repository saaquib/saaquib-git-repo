#include"header.h"

void delete_at_given_position(int pos)
{
	NODE *prev;
	NODE *traverse;
	
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
			prev = traverse;
			traverse = traverse->link;
		}
		prev->link = traverse->link;
		free(traverse);
		count--;
	}
}
