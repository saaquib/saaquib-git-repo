#include"header.h"

void insert_at_end(void)
{
	NODE *temp;
	NODE *traverse;
  	temp = create();
	char ch_element[MAX];
	int element;

	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);

	if (head == NULL) {
		insert_at_begining();
	}
	else {
		traverse = head;
		while(traverse->link != head) {
			traverse = traverse->link;
		}
		traverse->link = temp;
		temp->link = head;
		temp->data = element;
		count++;
	}
}
