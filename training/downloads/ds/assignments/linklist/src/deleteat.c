#include "header.h" //include header

sl *deleteat(sl *head) //delete at particular position function
{
	int position; //position where th node is deleted
	char *str = NULL; //pointer to take input position
	int i = 0; //temporary variable to count number of nodes
	sl *temp = NULL; //temporary pointer to access list

	temp =  (sl *)malloc(sizeof(sl)*MAX); //dynamic memory allocation 
	
	str = (char *)malloc(sizeof(char)*MAX); //dynamic memory allocation

	temp = head; //geeting head value to temp

	printf ("enter the position\n"); //asking to give input position
	fgets(str,MAX,stdin); //taking input as the string
	position = atoi(str); //conversion to integer from string

	while (temp != NULL ){ //traversing through the list
		temp = temp -> next;
		i++;
	}
	if (position > i && position <= 0) 
				//checking whether the position is available or not
		printf("the element is not there to delete\n");

	else if ( position == 1 ) //if the position is first
		head = head -> next;

	else //for remaining positions
		temp = head;
		while ((position) > 0 ) 
			temp = temp -> next;
		temp -> next = (temp -> next) -> next;
	

	return head; //return head to the called function
}
	
	
	
	

