#include <unistd.h>                                                           
//#include <errno.h>                                                            
#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>    
#include <signal.h>
#include<pthread.h>

void *thread (void *ar)
{
	char *line =(char *)ar;
	int seconds;
	char msg[64];                                                                        
	if (sscanf(line, "%d %64[^\n]", &seconds, msg) < 2) {                   
		fprintf (stderr, "bad coomand\n");                                  
	} else { 
		sleep(seconds);                                                 
		printf ("[%d] %s\n", seconds, msg);   
	}
}         


int main (int argc, char *argv[])                                               
{                                                                               

	int seconds;                                                                
	char line[120];                                                             
	char msg[64];         
	int time;




	while(1) {                                                                  
		pthread_t th_id;
		printf ("alaram..");      
		if (NULL ==(fgets(line, sizeof(line), stdin))) {                        
			printf ("fgets failed..\n");                                        
			exit (0);                                                           
		}                                                                       
		if (strlen (line) <= 1) continue;    

		pthread_create(&th_id,NULL, thread, &line);
	}                                                                   

	pthread_exit(NULL);                                                                                
	return 0;                                                                   
}     
