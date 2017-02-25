#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX 100

int main (void) {

	int sd;
	int cd;
	char ser_msg[100] = "This_is_saaquib...naam_toh_suna_hi_hoga...";
	char cli_msg[100] = {'\0'};
	socklen_t peer_addr_size;
	struct sockaddr_in my_addr;
	struct sockaddr_in peer_addr;

	peer_addr_size = sizeof (struct sockaddr_in);
	my_addr.sin_family = PF_INET;
    my_addr.sin_port = htons(6440);
    my_addr.sin_addr.s_addr = htonl(0xac1005fb);

	sd = socket (PF_INET, SOCK_STREAM, 0);
	if (sd == -1) {
		perror ("socket error\n");
	}

	if (connect (sd, (struct sockaddr *)&my_addr, peer_addr_size) < 0) {
		perror ("connectt error\n");
		exit (1);
	}

	while(1) {
		printf("me : ");
		if (NULL == fgets (cli_msg, MAX, stdin)) {
			perror ("fgets error\n");
			exit (0);
		}
		
		printf("waiting for server's reply...\n");
		if (write(sd, cli_msg, MAX) < 0) {
			perror ("write error\n");
			exit (0);
		}

		if (read(sd, ser_msg, MAX) < 0) {
			perror ("read error\n");
			exit (0);
		}

        printf("server : %s\n",ser_msg);
        memset(ser_msg, '\0', sizeof(ser_msg));
        memset(cli_msg, '\0', sizeof(cli_msg));

		if (!strcmp (cli_msg, "bye\n")) {
			break;
		}
   	}
   	close(sd);
	return 0;
}
