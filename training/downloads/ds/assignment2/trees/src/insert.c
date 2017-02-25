#include "header.h"

node *insert(node *root)                                                        
{
	char * str = NULL;
	
	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX) ) ) {
		printf("malloc failed\n");
		exit(0);
	}
                                                                               
    node *n1 = NULL;                                                            
    if ( NULL == (n1 = (node *)malloc(sizeof(node)*MAX)	) ) {
		printf("malloc failed\n");
		exit(0);
	}
                                      
    node *temp = NULL; 
                                                         
    if ( NULL == (temp = (node *)malloc(sizeof(node)*MAX) ) ) {
		printf ("malloc failed\n");
		exit(0);
	}
                                    
    int element;                                                                
    printf("enter the element to be inserted\n"); 

    if ( NULL == (fgets(str,MAX,stdin))) {
		printf("entered wrong input\n");	
		exit(0);
	}	                          
                                                         
	element = atoi(str);
 
    if ( root == NULL ) {                                                       
        n1 -> data = element;                                                   
        n1 -> left = NULL;                                                      
        n1 -> right = NULL;                                                     
        root = n1;                                                              
        return root;                                                            
    }                                                                           
                                                                                
    temp = root;                                                                
    while ( temp != NULL ) {                                                    
        if ( element > temp -> data ) {                                         
            if ( temp -> right == NULL ){                                       
                n1 -> data = element;                                           
                n1 -> left = NULL;                                              
                n1 -> right = NULL;                                             
                temp -> right = n1;                                             
                return root;                                                    
            }                                                                   
            temp = temp -> right;                                               
        }                                                                       
        else {                                                                  
            if (temp -> left == NULL ) {                                        
                                                                                
                n1 -> data = element;                                           
                n1 -> left = NULL;                                              
                n1 -> right = NULL;                                             
                temp -> left = n1;                                              
                return root;                                                    
            }                                                                   
            temp = temp -> left;                                                
        }  
	}
}
