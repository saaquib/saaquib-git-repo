#include"header.h"

void insert_at_given_position(int pos)
{
	NODE *temp;
	NODE *traverse;
	temp = create();
	char ch_element[MAX];
	int element;

	if (pos == 0) {
		insert_at_begining();
	}else if (pos >= count) {
		printf("\nSize out of bound");
		printf("\nMax position is : %d",count - 1);
	}
	else {
		printf("\nEnter element: ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		element = is_valid(ch_element);
		traverse = head;
		while(--pos)
			traverse = traverse->link;
		temp->link = traverse->link;
		traverse->link = temp;
		temp->data = element;
		count++;
	}
}
