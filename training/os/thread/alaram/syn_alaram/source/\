/*
//#include <header.h>
                                                                        
//#include <unistd.h>                                                     
//#include <errno.h>                                                      
#include <stdio.h>                                                      
#include <stdlib.h>                                                     
#include <string.h>            
*/
#include"header.h"

int main (int argc, char *argv[])
{

	int seconds;
	char line[120];
	char msg[64];

	while(1) {
		printf ("alaram..");
		if (NULL ==(fgets(line, sizeof(line), stdin))) {
			errno_abort("fgets failed..\n");
			exit (0);
		}
		if (strlen (line) <= 1) continue;
	
		if (sscanf(line, "%d %4[^\n]", &seconds, msg) < 2) {
			errno_abort("bad coomand\n");
		} else {
				sleep(seconds);
				printf ("[%d] %s\n", seconds, msg);
			}
		
	}

	return 0;
}		
