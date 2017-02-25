#include "header.h"

sl *del(sl *head)
{
	int option;
	char *str = NULL;
	str = (char *)malloc(sizeof(char)*MAX);
	printf("choose one option\n");
	printf("1. delete at the begining\n");
	printf("2. delete at the end\n");
	printf("3.delete in the middle\n");
	printf("4.delete at particular position\n");
	printf("5.delete after particular position\n");
	printf("6.delete before any position\n");
	printf("7.delete after particular number\n");
	printf("8.delete before particular number\n");
	fgets(str,MAX,stdin);
	option = atoi(str);
	
	switch(option) {
		case 1:
				head = deletebeg(head);
				break;
		case 2:
				head = deleteend(head);
				break;
		case 3:
				head = deletemid(head);
				break;
		case 4:
				head = deleteat(head);
				break;
		case 5:
				head = delafter(head);
				break;
		case 6:
				head = delbef(head);
				break;
		case 7:
				head = delaftnum(head);
				break;
		case 8:
				head = delbefnum(head);
				break;
		default :
				printf("enter correct option\n");

	}
	
	return head;
}
