#include "header.h"
	
sl *insertend(sl *head)
{
	char *str = NULL;
	int element;
	sl *new = NULL;
	sl *temp = NULL;
	str = (char *)malloc(sizeof(char)*MAX);
	new = (sl *)malloc(sizeof(sl)*MAX);
	temp = (sl *)malloc(sizeof(sl)*MAX); 

	printf("enter the element to be inserted\n");
	fgets(str,MAX,stdin);
	element = atoi(str);
	temp = head;
	
	if ( head == NULL ) {
		new -> data = element;
		new -> next = NULL;
		head = new;
	}
	else {
		while ( (temp -> next) != NULL ) {
			temp = temp -> next;
		}
		new -> data = element;
		temp -> next = new;
		new -> next = NULL;
	}
	return head;
}
		
