#include"header.h"

void insert_at_penultinate(void)
{
	NODE *temp;
	NODE *traverse;
	NODE *prev;
	temp = create();
	char ch_element[MAX];
	int element;
	
	if (head == NULL) {
		printf("\n LIst is empty");
	} else if (count == 1) {
		insert_at_begining();
	} else if (count > 1) {
		printf("\nEnter element: ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		element = is_valid(ch_element);

		traverse = head;
		while(traverse->link != NULL)  {
			prev = traverse;
			traverse = traverse->link;
		}
		temp->link = traverse;
		prev->link = temp;
		temp->data = element;
		count++;
	}
}
