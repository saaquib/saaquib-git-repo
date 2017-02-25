//main function for operations of queue

#include "header.h" //include header file                                                             
                                                                                
int main() //main fnction                                                                     
{                                                                               
    int option; //option to enter switch case                                                                
    int element; //element to enter the queue
	char *str = NULL; //character string to get the input from the user
                                                     
    front = -1; //initialising the front with -1
	rear = -1;  //initialising the rear with -1
    
	//validating malloc for str                                                             
    if ( NULL == (str = (char *)malloc(sizeof(char)*MAX) ) ) {
		perror("malloc failed\n");
		exit(0);
	}                                     
    while (1) {  //infinite loop to xecute switch case again and again                                                                
                                                                                
    printf("enter 1 for push\nenter 2 for pop\nenter 3 for display\n");         
    printf("enter 4 to exit\n");                                                
    
	//validating fgets for str                                                                            
    if ( NULL == (fgets(str,MAX,stdin) ) ) {
		perror("fgets failed for str\n";
		exit(0);
	}
                                                       
    option = atoi(str); //validating input and converting from string to int                                                        
                                                                                
    switch(option) { //enter switch case                                                           
                                                                                
        case 1: //if the case is enqueue                                                                
                printf("enter the element to be enqueued\n");                     
                fgets(str,MAX,stdin);                                           
                element = atoi(str);                                            
                enqueue(element);                                                  
                break;
                                                          
        case 2: //if the case is dequeue                                                                 
                element = dequeue();                                                
                printf("the element dequeued is: %d\n",element);                  
                break;                  
                                        
        case 3:  //if the case is display                                                               
                display();                                                      
                break;                   
                                       
                                                                                
        case 4: //if the case is exit                                                                
                return 0;            
                                           
        default : //for all the inputs othr than specified                                                              
                printf("entered wrong option\nplease enter correct option\n");  
                                                                                
        }   
	}

	return 0;
}
