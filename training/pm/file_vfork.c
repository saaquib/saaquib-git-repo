#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#define MAX 32
int main (void) {

    FILE *fp;
    fp = fopen ("file_vfork.text","w+");

    pid_t pid = vfork ();

    if (pid == 0) {
        printf ("<-----CHILD----->\n");
		char *child_str;
        child_str = (char *) malloc ( sizeof (char) * MAX );
        printf ("CHILD PID : %d \n", getpid ());
        printf("Enter child string: ");  
        fgets (child_str,MAX,stdin);
        fputs (child_str,fp);       
        fclose (fp);
        exit (0);
    }
//  getchar ();
    if (pid > 0) {
        fp = fopen ("file_vfork.text","r+");
		wait ();	
	    printf ("<-----PARENT----->\n");
        char *parent_str;
        parent_str = (char *) malloc ( sizeof (char) * MAX );
		printf("Enter parent string: ");
        fgets (parent_str,MAX,stdin);
        fputs (parent_str,fp);
        fclose (fp);
    }
    return 0;
}
