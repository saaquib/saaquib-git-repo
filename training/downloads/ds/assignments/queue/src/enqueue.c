//enqueue operation of queue function

#include "header.h" //include the header file

void enqueue (int element) //function definition for enqueue
{
	if ( rear >= MAX-1 ) //checking if the queue is full or not
		printf("the queue is full\n");
	else { //if the queue is not full
		rear = rear + 1; //incrementing rear
		queue[rear] = element; //storing the element in particular position
	}
}

