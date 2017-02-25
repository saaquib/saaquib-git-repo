#include "header.h"                                                             
void enqueue (int element)                                                      
{                                                                               
    if ( count >= MAX)                                                        
        printf("the queue is full\n");                                          
    else {     
		if (rear == (MAX -1) )
			rear = -1;                                                                 
        rear = rear + 1;                                                        
        queue[rear] = element; 
		count ++;                                                 
    }                                                                           
}   
