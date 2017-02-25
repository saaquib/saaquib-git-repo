#include "header.h"

void delete (void) {
	NODE *traverse;
	NODE *temp;
	temp = (NODE *) malloc (sizeof(NODE));
	traverse = (NODE *) malloc (sizeof(NODE));
	temp = head;
	traverse = head;

	if (temp == NULL) {
		printf("\nempty");
		return;
	
	}
	else {
		while (temp -> link != head) {
			temp = temp -> link;
		}
		temp -> link = traverse -> link;
		head = traverse -> link;
		free (traverse);
		return;
	}
}
