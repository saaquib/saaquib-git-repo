
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

int glob = 4;
void *thread1 (void *arg)
{
	FILE *fp =(FILE *)arg;
/*	char *str = (char *)arg;
	printf ("string in thread...%s\n",str);
	strcpy(str,"geetha");
	//str = "geetha";
	printf ("string in thread aft...%s\n",str);*/

	fprintf(fp,"hello\n");
//	fclose(fp);
	/*	int *loc = (int *)arg;
		printf ("hiiiiiiii thread....\n");
		printf ("glob in thread...%d\n", glob);
		printf ("loc in thraed...%d\n", *loc);
		glob = glob + 2;
	 *loc = *loc + 2;

	 printf ("glob in thread...%d\n", glob);
	 printf ("loc in thraed...%d\n", *loc);
	 */ 
}


int main()
{
	/*struct p {
		int loc;
*/
		
	int loc = 10;
	int err;
	char *ptr =NULL;
	FILE *fp = NULL;
	
	ptr = (char *)malloc(sizeof(int) *10);

	//printf ("enter the string\n")
	//	ptr = "nvnl";
	//	strcpy(ptr, "nvnl");

	if (NULL == (fp = fopen("hii.txt", "w+")))
	{
		printf ("file not created\n");
		exit (0);
	}
	pthread_t t_id;


	//err = pthread_create (&t_id, NULL, thread1, &loc);
	//err = pthread_create (&t_id, NULL, thread1, ptr);
	err = pthread_create (&t_id, NULL, thread1, NULL);
	getchar();
	if (err != 0)
		printf ("thread is not cread\n");
	else
		printf ("thread is created in process\n");
	fprintf (fp, "hiii\n");
	fclose(fp);
	
	glob = glob + 2;
	printf ("glob in process...%d\n", glob);
	printf ("local in process...%d\n", loc);
	printf ("string is...%s\n",ptr);
	strcpy(ptr,"chiii");
	//ptr = "chiii";
	printf ("string is aft...%s\n",ptr);
	pthread_exit(NULL);
	return 0;
}

