#include "header.h"

sl *insertbef(sl * head)
{
	int i = 0;
	sl *temp = NULL;
	sl *new = NULL;
	char *str = NULL;
	sl *temp1 = NULL;
	int position;
	int element;

	temp = (sl *)malloc(sizeof(sl)*MAX);
	temp1 = (sl *)malloc(sizeof(sl)*MAX);
	new = (sl *)malloc(sizeof(sl)*MAX);
	
	str = (char *)malloc(sizeof(char)*MAX);

	printf("enter the position for the node to be inserted\n");
	fgets(str,MAX,stdin);
	position = atoi(str);

	printf("enter the elemet to be inserted\n");
	fgets(str,MAX,stdin);
	element = atoi(str);

	temp = head;
	
	while(temp != NULL) {
		i++;
		temp = temp -> next;
	}
	
	if( position > i ) {
		printf("element can't be inserted at that position\n");
	}	
	
	else if(position <= i ){
		temp = head;
		i = position - 2;
		while ( (--i) > 0 ) {
			temp = temp -> next;
		}
	//	printf("data-%d\n",temp1->data);
		new -> next = temp -> next;
		new -> data = element;
		temp -> next = new;
	}
	return head;
}
	
