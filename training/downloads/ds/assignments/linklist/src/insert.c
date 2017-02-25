#include "header.h"

sl *insert(sl *head)
{
	int option;
	char *str = NULL;
	str = (char *)malloc(sizeof(char)*MAX);
	printf("choose one option\n");
	printf("1. insert at the begining\n");
	printf("2. insert at the end\n");
	printf("3.insert in the middle\n");
	printf("4.insert at particular position\n");
	printf("5.insert after particular position\n");
	printf("6.insert before any position\n");
	printf("7.insert after particular number\n");
	printf("8.insert before particular number\n");
	fgets(str,MAX,stdin);
	option = atoi(str);
	
	switch(option) {
		case 1:
				head = insertbeg(head);
				break;
		case 2:
				head = insertend(head);
				break;
		case 3:
				head = insertmid(head);
				break;
		case 4:
				head = insertat(head);
				break;
		case 5:
				head = insertafter(head);
				break;
		case 6:
				head = insertbef(head);
				break;
		case 7:
				head = insertaftnum(head);
				break;
		case 8:
				head = insertbefnum(head);
				break;
		default :
				printf("enter correct option\n");

	}
	
	return head;
}
