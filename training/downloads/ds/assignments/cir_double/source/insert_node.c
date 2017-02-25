#include"header.h"                                                              
                                                                                
cdll insrt_node(cdll head)                                                         
{                                                                               
    char str1[MAX];                                                             
    cdll cur_node = NULL;                                                        
    cdll new_node = NULL;                                                        
  	                                                             
    new_node = DYN;                                                             
    cur_node = DYN;                                                             
                                                                                
    printf ("enter the element:\n");                                              
    if (NULL == fgets(str1, MAX, stdin)) {                                      
            printf("enter valid input:");                                       
            exit(0);                                                            
    }                                                                           
    new_node -> data = atoi(str1);                                              
//this is just entering the data NULL to newnode                                                 
                                               
                                                                                
    if (head == NULL) {                                                         
        head = new_node;                                                        
        new_node -> prev = NULL;
		new_node -> next = new_node;                                                
    }                                                                           
                                                                                
    else {                                                                      
        cur_node = head;                                                        
        while(cur_node -> next != head) {//traverse till the NULL occur                                         
            cur_node = cur_node -> next;                                        
        }                                                                       
                                                                                
        cur_node -> next = new_node;//adding the newnode to the last node                                            
        new_node -> prev = cur_node;
		new_node -> next = head;                                            
    }                                                                           
                                                                                
    printf ("...node is added at the end....:\n");                              
    return head;                                                                
}                     
