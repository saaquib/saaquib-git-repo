#include "header.h"

void display(dll *head)
{
	dll *temp;
	
	temp = dms(temp);
	
	temp = head;

	if( temp == NULL )
	printf("no elements in list\n");
	
	else {
		printf("the elements in list are\n");
	
	while ( temp ->next != NULL ){
		temp = temp -> next;
		
	}
	while (temp != NULL) {
		printf("%d\t",temp -> data);
		temp = temp -> previous;
	}
	
	printf("\n");
}
}
