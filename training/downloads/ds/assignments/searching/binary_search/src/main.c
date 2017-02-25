#include "header.h" //include header file                                       
//int n;                                                                        
int main()                                                                      
{                                                                               
    int a[20];                                                                  
    int key;                                                                    
    char *str = NULL;                                                           
    int i;                                                                      
    str = (char *)malloc(sizeof(char)*MAX);                                     
                                                                                
    printf("enter the number of elements\n");                                   
    fgets(str,MAX,stdin);                                                       
    n = atoi(str);                                                              
                                                                                
    printf("enter the elements in the list\n");                                 
                                                                                
    for ( i=0; i<n; i++ ) {                                                     
        fgets(str,MAX,stdin);                                                   
        a[i] = atoi(str);                                                       
    }                                                                           
                                                                                
    printf ("enter the element to be searched\n");                              
    fgets(str,MAX,stdin);                                                       
    key = atoi(str);                                                            
                                                                                
    n = binary_search(a,key);                                                   
    if ( n == 1 )                                                               
        printf("the element is found\n");                                       
    else                                                                        
    printf("the element is not found\n");                                       
}   
