//push an element in stack function

#include "header.h" //include header file

void push(int element) //push an element function
{
	if(top == MAX-1) //check if stack is full or not
		printf("the stack is full and elements cant be inserted\n");
	else { //if stack is not full
		top = top+1; //increment stack
		stack[top] = element; //push an element
	}
}
