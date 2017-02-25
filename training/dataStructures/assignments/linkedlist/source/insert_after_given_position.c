#include"header.h"

void insert_after_given_pos(int pos)
{
//	create(n[count]);
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
		pos++;
		while(--pos)
			traverse = traverse->link;
		temp->link = traverse->link;
		traverse->link = temp;
		temp->data = element;
		count++;
	}
}
