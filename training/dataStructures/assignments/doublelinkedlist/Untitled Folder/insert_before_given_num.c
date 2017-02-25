#include"header.h"

void insert_before_given_num(int num)
{
//	create(n[count]);
	NODE *temp;
	NODE *traverse;
	NODE *previous;
	temp = create();
	char ch_element[MAX];
	int element;
	
	traverse = head;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);

	while(traverse->data != num) {
		previous = traverse;
		traverse = traverse->next;
	}
	
	temp->next = previous->next;
	previous->next = temp;
	traverse->prev = temp;
	temp->data = element;
}
