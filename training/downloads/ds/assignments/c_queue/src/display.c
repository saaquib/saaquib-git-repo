//display function of circular queue

#include "header.h" //include header file                                                             
                                                                                
void display() // display function of circular queue                                                                 
{                                                                               
    int i = front; //i is a variable starts from front used to traverse queue
	int temp; //temp is a variable to store count 
	temp = count; //assigning count to temp
	                                                                      
    if ( count == 0 ) { //if no elements in queue
		printf("the queue is empty\n");
	//	exit(0);
	} 
	else {                                                                            
   		printf("the elements in the queue are\n");                                  
    	while ( temp ) {   //traverse through queue
			if ( i == MAX - 1 ) //if posiition reached last of the queue
			i = -1; //starting it from the begining
			i ++;   //incrementing and extracting next element                                  
        	printf("%d\t",queue[i]); //printing the element
			temp --; //decreasing the count 
		}                                             
        	printf("\n");                                                           
	}
}   
