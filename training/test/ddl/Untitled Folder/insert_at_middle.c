#include"header.h"

void insert_at_middle()
{
	int count = 0;
//	create(n[count]);
	NODE *temp;
	NODE *traverse;
	temp = (NODE *)malloc(sizeof(NODE));
	char ch_element[MAX];
	int element;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	element = is_valid(ch_element);

	traverse = head;
	while(traverse->link != NULL)  {
		traverse = traverse->link;
		count++;
	}
	count = (count / 2) + 1;
	traverse = head;
	while(--count)
		traverse = traverse->link;

	temp->link = traverse->link;
	traverse->link = temp;
	temp->data = element;
}
