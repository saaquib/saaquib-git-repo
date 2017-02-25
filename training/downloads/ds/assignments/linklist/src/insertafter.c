#include "header.h"

sl *insertafter(sl * head)
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
//	printf("i=%d",i);
	
	if( position > i ) {
		printf("element can't be inserted at that position\n");
	}	
	
	else if(position <= i ){
		temp1 = head;
		while ( --position ) {
			//printf("check\n");
			temp1 = temp1 -> next;
		//	position --;
		}
		printf("data-%d\n",temp1->data);
		new -> data = element;
		new -> next = temp1 -> next;
		temp1 -> next = new;
	}
	return head;
}
	
