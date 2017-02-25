#include"header.h"

void insert_before_given_num(int num)
{
//	create(n[count]);
	NODE *temp;
	NODE *traverse;
	NODE *prev;
	temp = create();
	char ch_element[MAX];
	int element;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);

	traverse = head;
	while((traverse->data != num) && (traverse->link != NULL))  {
		prev = traverse;
		traverse = traverse->link;
	}
	if (traverse->data == num) {
		temp->link = traverse;
		prev->link = temp;
		temp->data = element;
		count++;
	}	
	else {
		printf("\nEntered element is not in the list");
	}
}
