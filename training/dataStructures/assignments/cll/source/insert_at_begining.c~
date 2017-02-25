#include"header.h"

void insert_at_begining(void)
{
	NODE *temp;
	NODE *traverse;
	NODE *head2;
	temp = create();
	char ch_element[MAX];
	int element;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);
	if (head == NULL) {
		head = temp;
		temp->link = head;
		temp->data = element;
		count++;
	}
	else {	
		head2 = head;
		temp -> link = head;
		temp -> data = element;
		head = temp;
		traverse = head2;
		while(traverse->link != head2) {
			traverse = traverse->link;
		}
		traverse -> link = head;
		count++;
	}
	return;
}
