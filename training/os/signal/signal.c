#include<stdio.h>
#include <signal.h>
//sighandler_t handler ;
void handler (void); 
int main(void) {
	int *t;

	signal (SIGSEGV,&handler);
	t = 4;
	printf("t = %d\n",*t);
	printf("ting tong\n");
	pause ();	
	return 0;
}

void handler (void) {
	//if ( num == SIGSEGV ) {
		printf("recieved signal\n");
		exit (0);
	//}
	return;
}
