#include "header.h"                                                             
                                                                                
int dequeue()                                                                   
{                                                                               
    int element;                                                                
    if ( count == 0 )                                                       
        printf("the queue is empty\n");                                         
    else {         
		if ( front == MAX-1 )
		front = -1;                                                             
        front = front + 1;                                                      
        element = queue[front];
		count --;                                                 
    }                                                                           
	printf("queue[0] = %d\n",queue[0]);
	printf("addr = %p\n",&queue[0]);
    return element;                                                             
}    
