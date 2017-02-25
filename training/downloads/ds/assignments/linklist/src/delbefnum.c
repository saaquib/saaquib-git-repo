#include "header.h" //include header

sl *delbefnum(sl *head) //delete at particular position function
{
	int number; //position where th node is deleted
	char *str = NULL; //pointer to take input position
	int i = 0; //temporary variable to count number of nodes
	sl *temp = NULL; //temporary pointer to access list
	int count = 0; //temporary count variable to count position

	temp =  (sl *)malloc(sizeof(sl)*MAX); //dynamic memory allocation 
	
	str = (char *)malloc(sizeof(char)*MAX); //dynamic memory allocation

	temp = head; //geeting head value to temp

	printf ("enter the number\n"); //asking to give input position
	fgets(str,MAX,stdin); //taking input as the string
	number = atoi(str); //conversion to integer from string

	while (temp != NULL ){ //traversing through the list
			if (temp -> data == number){
				i = 1;
				break;
 			}
		temp = temp -> next;
		count ++;
	}
	temp = head;
	if ( i == 0) 
				//checking whether the position is available or not
		printf("the element is not there to delete\n");

	else if ( count == 2 ) //if the position is first
		head = temp -> next;

	else //for remaining positions
		temp = head;
		count = count-1;
		while ((--count) > 0 ) 

			temp = temp -> next;
		temp -> next = (temp -> next) -> next;
	

	return head; //return head to the called function
}
	
	
	
	

