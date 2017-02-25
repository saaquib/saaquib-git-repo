#include<stdio.h>                                                               
#include<string.h>                                                              
#include<pthread.h>                                                             
#include <unistd.h>                                                             
#include <sys/syscall.h>                                                        
#include <sys/types.h>                                                          
#include <signal.h>                                                             
                                                                                
void *thread_function (void *p) {                           
	int *d = (int *)p;                    
    printf("Inside thread funtion\n");                                          
    printf("Thread PID :  %d\n",getpid ());                                     
    printf("Thread's Thread ID :  %ld\n",syscall (SYS_gettid));                 
//    printf ("a : %d\n",a);                                                      
//  printf ("b : %d\n",b);                                                      
  printf ("c : %d\n",*d);                                                      
	printf("<----- Exiting parent----->\n");
	getchar ();   
    return NULL;                                                                
}                                                                               
                                                                                
int a = 4;                                                                      
                                                                                
int main (void) {                                                               
    int status;                                                                 
    pthread_t th_id;                                                            
  	int b = 10;
	
	int *c;
	c = (int *) malloc (sizeof (int));
	*c = 14;         
	printf("a before modifying: %d\n",a);                                                                    
	a = 5;
    status = pthread_create (&th_id, NULL, thread_function, &a);              
    if (status != 0) {                                                          
        printf("Thread creation failed : %s\n", strerror (status));             
    }                                                                           
                                                                                
    printf("Inside Parent \n");                                                 
    printf("Parent PID :  %d\n",getpid ());                                     
    printf("Parent's Thread ID :  %ld\n",syscall (SYS_gettid));                 
                                                                                
    printf ("a : %d\n",a);                                                      
    printf ("b : %d\n",b);                                                      
    printf ("c : %d\n",*c);                                                      
    getchar ();                                                                 
	printf("<----- Exiting parent----->\n");
    pthread_exit (NULL);                                                        
    return 0;                                                                   
}
