//stack implementation in data structures

#include "header.h" //include header file

int main() //main function
{
	int option; //variable option to enter switch case
	int element;//variable element to hold the value to be pushed into stack
	char *str; //character string to get input from the user

	top = -1; //initialising top value of stack to -1
	
	//validating malloc for character string str
	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX) ) ) {
		perror("malloc failed\n");
		exit(0);
	}
	while (1) { //infinite loop to execute switch again and again
	printf("enter 1 for push\nenter 2 for pop\nenter 3 for display\n");
	printf("enter 4 to exit\n");
	
	// validating fgets for str	
	if ( NULL == (fgets(str,MAX,stdin) ) ) {
		perror("entered wrong input\n");
		exit(0);
	}

	option = atoi(str); //validating input by atoi conversion

	switch(option) { //enter switch case
	
		case 1: //if the case is push
				printf("enter the element to be pushed\n");
				fgets(str,MAX,stdin);
				element = atoi(str);
				push(element);
				break;

		case 2: //if the case is pop
				element = pop();
				printf("the element popped is: %d\n",element);
				break;

		case 3: //if the case is display
				display();
				break;

		case 4://if the case is exit
				return 0;

		default : //for all other inputs other than specified
				printf("entered wrong option\nplease enter correct option\n");
				
		}
	}

	return 0;
}
	
