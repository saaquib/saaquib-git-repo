//display the elements in the queue function

#include "header.h" //include the header file

void display() //display function deinition
{
	int i; //variable to traverse the queue
	
	printf("the elements in the queue are\n");	
	for ( i = front+1 ; i <= rear ; i++) //traverse the queue
		printf("%d\t",queue[i]); //printing the element of queue
		printf("\n");
}
