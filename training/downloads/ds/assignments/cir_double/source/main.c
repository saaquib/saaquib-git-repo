#include"header.h"                                                              
                                                                                
int main()                                                                      
{                                                                               
    char str[MAX];                                                              
    int op;                                                                     
    int c;                                                                      
    head = NULL;                                                                
                                                                                
    while(1) {                                                                  
                                                                                
        printf ("1.add....\n2.display....\n3.delete node....\n");               
        printf("4.exit...\nenter the option:\n");                                          
        printf ("\n");                                                          
        scanf("%d", &op);
		getchar();                                                       
                                                                                
        switch(op) {                                                            
            case 1:                                                             
                head = insrt_node(head);                                       
                break;                                                          
            case 2:                                                             
                display(head);                                                  
                break;                                                          
                                                                    
            case 3:                                                             
                head = delet_node(head);                                        
                break;                                                          
            case 4: exit(0);                                                    
        }                                                                       
                                                                                
    }                                                                           
    return 0;                                                                   
}              
