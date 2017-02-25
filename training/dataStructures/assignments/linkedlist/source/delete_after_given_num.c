#include"header.h"

void delete_after_given_num(int num)
{
	NODE *traverse;
	NODE *prev;	
	traverse = head;
	if (count == 0) {
		printf("\n No elements in the list");
		return;
	}
	else {
		while((traverse->data != num) && (traverse->link != NULL)) {
			prev = traverse;
			traverse = traverse->link;
		} 
		if(traverse->link == NULL) {
				printf("no elements");
		} else if (traverse->data == num) {
			prev = traverse;
			traverse = traverse->link;
			else  
			{
				prev->link = traverse->link;
				free(traverse);
				count--;
			}
		}
		else {
			printf("\nElement not found");
		}
	}
}
