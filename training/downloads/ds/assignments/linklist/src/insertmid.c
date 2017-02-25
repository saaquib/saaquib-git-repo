#include "header.h"

sl *insertmid(sl *head)
{
	int i = 0;
	int n;
	sl *temp = NULL;
	sl *new = NULL;
	char *str = NULL;
	int element;

	str = (char *)malloc(sizeof(char)*MAX);	
	temp = (sl *)malloc(sizeof(sl)*MAX);
	new = (sl *)malloc(sizeof(sl)*MAX);   

	printf("enter the element to be inserted\n");                           
        fgets(str,MAX,stdin);                                                   
        element = atoi(str);     

	if ( head == NULL ) {
		new -> data = element;
		new -> next = NULL;
		head = new;
	}

	
	else {
		temp = head;
		while ( temp != NULL ){
			i++;
			temp = temp -> next;
		}
		printf("i: %d\n",i);
		n = i/2;
		temp = head;
		 while ( n-1 ) {
			temp = temp -> next;
			n--;
		}

		new -> data = element;
		new -> next = temp -> next;
		temp -> next = new;
	}
	return head;
}
		
			
