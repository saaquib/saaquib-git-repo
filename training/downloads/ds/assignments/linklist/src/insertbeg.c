#include "header.h" //include header file

sl *insertbeg(sl *head) //function to insert at begining
{
	char *str = NULL; //string to get input
	int element; //integer variable to store input
	printf("enter the element to be inserted\n");
	str = (char *)malloc(sizeof(char)*MAX); //dynamic allocation of memory

	fgets(str,MAX,stdin); //getting input from user
	element = atoi(str); //conversion to integer from string

	sl *new; //creating a new variable of type sl
	new = (sl *)malloc(sizeof(sl)*MAX); //dynamic allocation of memory

	if ( head == NULL ) { //if the head is null
		new -> data = element;
		new -> next = NULL;
		head = new;
	}
	else {  //remaining conditions
		new -> data = element;
		new -> next = head;
		head = new;
	}
	return head;
}
		
		
		
