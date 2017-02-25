#include "header.h"

NODE* create(void)
{
	NODE* temp = (NODE *)malloc(sizeof(NODE));
	if(temp == NULL) {
		printf("node not created\n");
	}
	else {	
		temp->link = NULL;
	}
	return temp;
}
