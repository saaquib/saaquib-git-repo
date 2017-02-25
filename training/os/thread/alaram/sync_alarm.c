#include<stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	int seconds;
	char line[120];
	char message[64];

	while (1) {
		printf("Alarm\n");
		if (fgets (line, sizeof (line), stdin) == NULL) exit (0);
		if (strlen (line) <= 1) continue;

		if (sscanf (line, "%d %64[^\n]", &seconds, message) > 2) {
			fprintf(stderr, "Bad command\n");
		} else {
			sleep (seconds);
			printf("(%d) %s\n", seconds, message);
		}
	}
}
