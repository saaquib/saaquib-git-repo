#include"header.h"

void display(void)
{
	int track;
	int loc_front;
	loc_front = front;
	track = count;
	if(track == 0)   
		        printf("\nQueue is empty");

	while(track--) {
		printf("\t%d",queue[loc_front++]);
		if (loc_front == LIMIT) {
			loc_front = 0;
		}
	}
}
