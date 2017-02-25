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
	char ser_msg[100] = {'\0'};
	char cli_msg[100] = "This_is_kartheek...naam_toh_suna_hi_hoga...";
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
 printf("msg %s\n",cli_msg);       
	if (sendto(sd, cli_msg, sizeof(cli_msg), 0, (struct sockaddr *)&my_addr,peer_addr_size) < 0) {
            perror("sendto");
            exit(1);
        }

    if (recvfrom(sd, ser_msg, sizeof(ser_msg), 0, (struct sockaddr *)&peer_addr, &peer_addr_size) < 0) {
    	perror("recvfrom");
        exit(1);
    }

    printf("message from server \n");
    printf("msg : %s\n",ser_msg);

    close(sd);
	return 0;
}
