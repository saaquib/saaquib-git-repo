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

	sd = socket (PF_INET, SOCK_DGRAM, 0);
	if (sd == -1) {
		perror ("socket error\n");
	}

	if (bind (sd, (struct sockaddr *) &my_addr, sizeof (struct sockaddr_in)) == -1) {
		perror ("bind error\n");
	}
printf("msg : %s\n",ser_msg);
	 while(1) {
        if (recvfrom(sd, cli_msg, sizeof(cli_msg), 0, (struct sockaddr *)&peer_addr, &peer_addr_size) < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("request recevied \n");
        printf("msg %s\n",cli_msg);

        if (sendto(sd, ser_msg, sizeof(ser_msg), 0, (struct sockaddr *)&peer_addr,peer_addr_size) < 0) {
            perror("sendto");
            exit(1);
        }
        memset(cli_msg, '\0', sizeof(cli_msg));
    }
	
    close(sd);
	return 0;
}
