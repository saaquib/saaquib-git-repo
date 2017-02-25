//dequeue element from queue function

#include "header.h" //include header file

int dequeue() //dequeue function definition
{
	int element; //element that is dequeued from the queue
	if ( front+1 > rear ) //check if queue is empty or not
		printf("the queue is empty\n");
	else { //if queue is not empty
		front = front + 1; //increment the front
		element = queue[front]; //getting the element from queue
	}
	return element; //returning the element to the called function
}
