#include "header.h" //include header file

sl *deleteend(sl *head) //delete at the end function
{
	
	sl *temp = NULL; //temporary pointer to traverse the list
	
	temp = (sl *)malloc(sizeof(sl)*MAX); //dynamic memory allocation
	
	temp = head; //assigning head to temp variable

	while ( (temp -> next) -> next != NULL ) //traversing
		temp = temp -> next;

	 temp -> next = NULL; //making last one null
	return head; //returning head to the called function
}
