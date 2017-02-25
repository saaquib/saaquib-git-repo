#include <unistd.h>                                                           
//#include <errno.h>                                                            
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>    
#include <signal.h>
#include<pthread.h>

int main (int argc, char *argv[])                                               
{                                                                               

	int seconds;                                                                
	char line[120];                                                             
	char msg[64];         
	int time;
	
	signal (SIGCHLD,SIG_IGN);                                                                      
	while(1) {                                                                  
		printf ("alaram..");      
		pid_t p;
		if (NULL ==(fgets(line, sizeof(line), stdin))) {                        
			printf ("fgets failed..\n");                                        
			exit (0);                                                           
		}                                                                       
		if (strlen (line) <= 1) continue;    

		if (sscanf(line, "%d %64[^\n]", &seconds, msg) < 2) {                    
			fprintf (stderr, "bad coomand\n");                                  
		} else {     
			p = fork();
			if (p == 0) { //child process executing                                                         
				sleep(seconds);                                                 
				printf ("[%d] %s\n", seconds, msg);
				exit(0);      
			}
			//wait(NULL);//it will become synchronous program                       
		}                                                                   
	}                                                                           

	pthread_exit(NULL);                                                                                
	return 0;                                                                   
}     
