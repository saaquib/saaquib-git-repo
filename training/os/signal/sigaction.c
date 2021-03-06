#include<stdio.h>
#include<stdlib.h>
#include<signal.h>


void handler (int sig_no, siginfo_t *sig_info, void *p)  {
	siginfo_t *si;
	si = (siginfo_t *) malloc ( sizeof (siginfo_t ));
	si = sig_info;
	printf("recieved signal\n");
	printf("sig_no : %d\n",sig_no);
	printf ("si_signo : %d\n",sig_info -> si_signo);
	printf ("si_errno : %d\n",si -> si_errno);
	printf ("si_code : %d\n",si -> si_code);
	printf ("si_pid : %d\n",si -> si_pid);
	printf ("si_uid : %d\n",si -> si_uid);
	printf ("si_ptr : %p\n",(int *)si ->si_ptr);
	printf ("si_fd : %p\n",(int *)si -> si_fd);
	printf ("si_signo : %d\n",si -> si_signo);
	exit (1);
}

int main (void) {

struct sigaction act;
	int *t;
	t = 4;
//	act.sa_sigaction = NULL;
	act.sa_sigaction = &handler;
	act.sa_flags = SA_SIGINFO;

	sigaction (SIGSEGV, &act,NULL );

	printf("&t %p\n",&t);	
	*t = 8;

	return 0;
}
