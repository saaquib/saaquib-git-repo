#include"header.h"

NODE* insert_at_begining(void)
{
	NODE *temp;
	temp = (NODE *)malloc(sizeof(NODE));
	char ch_element[MAX];
	int element;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);

	temp->link = head;
	temp->data = element;
	head = temp;
	return head;
}
