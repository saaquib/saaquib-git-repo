#include"header.h"

void delete_given_num(int num)
{
	NODE *traverse;
	NODE *prev;	
	traverse = head;
	if (count == 0) {
		printf("\n List is empty");
	}
	else {
		while((traverse->data != num) && (traverse->link != NULL)) {
			prev = traverse;
			traverse = traverse->link;
		}
		if (traverse == head) {
			delete_at_begining();
		} else if (traverse->data == num) {
			prev->link = traverse->link;
			free(traverse);
			count--;
		}
		else {
			printf("\n Element not found");
		}
	}
}
