//function to pop an element from stack function

#include "header.h" //include header file

int pop() //pop function
{
	int element; //element poped from the stack
	if(top < 0) //check if stack is empty or not
		printf("stack is empty\n");
	else { //if stack is not empty
		element = stack[top]; //retrieve element from stack
		top = top - 1; //decrement stack top
	}
	return element; //return the result to the called function
}
