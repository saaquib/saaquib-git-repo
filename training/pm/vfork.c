#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#define MAX 32
int glob_1 = 4;
int main (void) {
	
	int loc_1 = 8;
	unsigned int *loc_heap;
	loc_heap = (unsigned int *) malloc (sizeof (unsigned int));
	*loc_heap = 12;
	FILE *fp;
	fp = fopen ("just.text","w+");
		
	pid_t pid = vfork ();
	
	if (pid == 0) {
		int loc_child = 20;
		char *child_str;
		child_str = (char *) malloc ( sizeof (char) * MAX );
		printf ("<-----CHILD----->\n");
		printf ("CHILD PID : %d \n", getpid ());
		printf ("glob_1 = %d \n",glob_1);
		printf ("Address of glob_1 = %p \n",&glob_1);
		printf ("loc_1 = %d \n",loc_1);
		printf ("Address of loc_1 = %p \n",&loc_1);
//		printf ("loc_heap = %p \n",loc_heap);
//		printf ("loc_heap value = %u \n",*loc_heap);
//		printf ("Address of loc_heap = %p \n",&loc_heap);
		printf ("Address of child_str = %p \n",&child_str);
//		printf ("loc_parent = %d\n",loc_parent);
		printf ("loc_child = %d\n",loc_child);
//		fgets (child_str,MAX,stdin);
//		fwrite (child_str,MAX,1,fp);
		exit (1);
	}
	getchar ();
	if (pid > 0) {
		char ch;
		int loc_parent = 16;
		char *parent_str;
		parent_str = (char *) malloc ( sizeof (char) * MAX );
		printf ("<-----PARENT----->\n");
		printf ("PARENT PID : %d \n", getpid ());
		printf ("glob_1 = %d \n",glob_1);
		printf ("Address of glob_1 = %p \n",&glob_1);
		printf ("loc_1 = %d \n",loc_1);
		printf ("Address of loc_1 = %p \n",&loc_1);
//		printf ("loc_heap = %p \n",loc_heap);
//		printf ("loc_heap value = %u \n",*loc_heap);
//		printf ("Address of loc_heap = %p \n",&loc_heap);
		printf ("loc_parent = %d\n",loc_parent);
		printf ("Address of parent_str = %p \n",&parent_str);
		printf ("Address of loc_parent = %p \n",&loc_parent);
//		fgets (parent_str,MAX,stdin);
//		printf ("loc_child = %d\n",loc_child);
//		fwrite (parent_str,MAX,1,fp);
	}
//		printf ("loc_parent = %d\n",loc_parent);
//		printf ("loc_child = %d\n",loc_child);
	return 0;
}
