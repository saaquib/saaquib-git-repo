#include "header.h"

dll *delete_mid(dll *head)
{
	dll *temp = NULL;
	temp = dms(temp);
	
	dll *temp2 = NULL;
	temp2 = dms(temp2);

	int count = 0;
	
	if ( head -> next == NULL ) {
		head  = NULL;
		return head;
	}
	
	temp = head;

	while ( temp->next != NULL) {  
		count++;
		temp = temp -> next;
	}

	printf ("%d-count\n",count);
	count = count/2;

	temp = head;

	while (--count)
		temp = temp -> next;
	
	temp2 = temp -> next;
	
	temp -> next = (temp -> next) -> next;
	temp -> next -> previous = temp;
	free(temp2);
	
	//free(temp2);

	return head;
} 
		

