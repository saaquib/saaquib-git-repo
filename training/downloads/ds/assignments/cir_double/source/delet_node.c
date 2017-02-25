//last node deletion                                                            
                                                                                
                                                                                
#include"header.h"                                                              
                                                                                
cdll delet_node(cdll head)                                                         
{                                                                                                                                               
                                                                                
    cdll cur_node = NULL;                                                        
    cur_node = DYN;//dynamic storage allocation                                                             
                                                                                
    cur_node = head;                                                            
    if (head == NULL) {                                                         
        printf ("list is empty:\n");                                            
    }                                                                           
                                                                                
    while ((cur_node -> next) != head) {//checking the next address...          
        cur_node = cur_node -> next;//for getting previous address              
    }                                                                           
    (cur_node -> prev) -> next = head;//and assigning previous address to null to make that as last                                                    
    printf ("first node is deleted\n");                                         
                                                                                
    return head;                                                                
}                                                                               
              
