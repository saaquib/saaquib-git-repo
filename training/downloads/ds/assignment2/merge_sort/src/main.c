#include "header.h"  //include header                                                           
                                                                                
int main()  //main function                                                                    
{                                                                               
                                                                                
    int a[20]; //array of elements given as input                                                                 
    char *str = NULL; //character string to get input from user                                                          
                                                                                
    int i = 0;  //temporary variable for loop
	
	int first = 0;
	int last;                           
                                                                                
    //dynamic memory allocatio of string                                                                            
    if ( NULL == (str = (char *)malloc(sizeof(char)*MAX))) {                    
        printf ("malloc failed\n");                                             
        exit(0);                                                                
    }                                                                           
                                                                                
    //getting input from user                                                   
                                                                                
    printf ("enter the number of elements\n");                                  
    if ( NULL == (fgets (str,MAX,stdin))) {                                     
        printf ("enter input\n");                                               
        exit(0);                                                                
    }                                                                           
    n = atoi(str); //converting to integer from string                                                              
                                                                                
    printf ("enter the elements\n");                                            
    last = n-1;                                                                            
    // getting input elements from the user                                     
                                                                                
    for( i = 0;i < n; i++ ) {                                                   
        if ( NULL == (fgets(str,MAX,stdin))) {                                  
            printf("enter input\n");                                            
            exit(0);                                                            
        }                                                                       
        a[i] = atoi(str);  //conversion to integer from string                                                     
    }                                                                           
                                                                                
    merge_sort(a,first,last); //calling selection sort function   

	//displaying the result after sorting                                       
                                                                                
    printf("the elements after sorting are\n");                                 
                                                                                
    for( i = 0; i < n; i++ )                                                    
        printf("%d\t",a[i] );                                                   

//	for( i = 0; i < n; i++ )                                                    
  //      printf("%d\t",b[i] );                                                                                  
}     
