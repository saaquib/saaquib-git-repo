//program for circular queue

#include "header.h" //include header file                                                             
                                                                                
int main()                                                                      
{                                                                               
    int option;//variable option to enter the case statement                                                                 
    int element; //element in which to be entered in the queue                                                                
    char *str; //character string to get the input from the user
	count = 0; //variable count to count current number of elements in queue                                                                 
    front = -1; //front position of the queue initialised with -1                                                                 
    rear = -1; //rear position of the queue initialised with -1
    
	//validating malloc for str                                                             
    if ( NULL == ( str = (char *)malloc(sizeof(char)*MAX) ) ) {
		perror("malloc failed\n");
		 exit(0);
	}
                                     
    while (1) {   //infinite loop to execute switch case                                                              
                                                                                
    printf("enter 1 for enqueue\nenter 2 for dequeue\nenter 3 for display\n");         
    printf("enter 4 to exit\n");                                                
    
	//validating fgets to take the input for option                                                                            
    if ( NULL == (fgets(str,MAX,stdin) ) ) {
		printf("entered wrong input\n");
		exit(0);
	}
                                                       
    option = atoi(str); //validating the integer                                                         
                                                                                
    switch(option) {  //enter the switch case                                                          
                                                                                
        case 1:  //if the case is enqueue                                                               
                printf("enter the element to be enqueued\n");                   
                if ( NULL == (fgets(str,MAX,stdin) ) ) {
					printf("entered wrong input\n");
					exit(0);
				}
		                                           
                element = atoi(str); //integer validation                                           
                enqueue(element); //calling enqueue function                                               
                break; 
                                                         
        case 2: //if the case is dequeue                                                                
                element = dequeue();  //calling function and store result in element                                          
                printf("the element dequeued is: %d\n",element);                
                break;
                                                          
        case 3: //if the case is display                                                                 
                display(); //call display function                                                     
                break;                                                          
                                                                                
        case 4:                                                                 
                return 0;                                                       
        default :                                                               
                printf("entered wrong option\nplease enter correct option\n");  
                                                                                
        } 
	}
	return 0;
}
