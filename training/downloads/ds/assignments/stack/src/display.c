//display the elements in stack functon

#include "header.h" //include header

void display() //display function definition
{
	int i = top; //assigning top to another variable
	if (top == -1) //checking if stack is empty or not
	printf("no elements in stack\n");
	else { //if the stack is not empty
	printf("the elements in the stack are\n");
	
	while(i+1){	//printing each element in the stack
		printf("%d\n",stack[i]);
		i--;
	}
	}

}
