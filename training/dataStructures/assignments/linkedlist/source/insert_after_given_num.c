#include"header.h"

void insert_after_given_num(int num)
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

	traverse = head;
	while((traverse->data != num) && (traverse->link != NULL)) 
		traverse = traverse->link;
	if (traverse->data == num) {
		temp->link = traverse->link;
		traverse->link = temp;
		temp->data = element;
		count++;
	}
	else {
		printf("\nEntered number is not present in the list");
	}
}
