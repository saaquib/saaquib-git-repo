#include "header.h"

sl *deletemid(sl *head)
{
	sl *temp = NULL; //taking a temporary pointer
	int count = 0; //variable to count the number of elements

	temp = (sl *)malloc(sizeof(sl)*MAX); //dynamic allocation of memory
	temp = head; //store head in temp
	while ( temp != NULL ){ //traverse through the list
		count++; //increment the count
		temp = temp -> next; //going to next element in the list
	}
	
	count = count/2; //getting the middle element
	temp = head; //storing head in temp again

	while( (--count) > 0 ){ //traversing till the desired position
		temp = temp -> next;
	}

	temp -> next = (temp -> next) -> next; //remove one element

	return head; //return head to the called function
} 
