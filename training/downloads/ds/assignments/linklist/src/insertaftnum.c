#include "header.h"

sl *insertaftnum(sl * head)
{
	int i = 0;
	int t = 0;
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

	printf("enter the number for the node to be inserted after\n");
	fgets(str,MAX,stdin);
	position = atoi(str);

	printf("enter the elemet to be inserted\n");
	fgets(str,MAX,stdin);
	element = atoi(str);

	temp = head;
	
	while(temp != NULL) {
		i++;
		if ( temp -> data == position ){
				t = 1;
				break;
		}
		temp = temp -> next;
	}
//	printf("i=%d",i);
	
		if ( t != 1)
		printf("element can't be inserted at that position\n");
		else {
		new -> data = element;
		new -> next = temp -> next;
		temp -> next = new;
	}
	return head;
}
	
