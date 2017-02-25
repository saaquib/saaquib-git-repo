//displaying the elements                                                       
#include"header.h"                                                              
void display(cdll head)                                                          
{                                                                               
    cdll temp = NULL;                                                            
                                                                                
    temp = DYN;                                                                 
    temp = head;                                                                
                                                                                
    while ((temp -> next) != head) {//traversing through the each node                    
        printf("%d==>\t", temp-> data);//while traversing printing the each node data
        temp = temp -> next;                                                    
                                                                                
    } 
	printf ("%d ==>\t", temp -> data);//for display rthe last element                                                                          
    printf ("\n");                                                              
}                                                                               
      
