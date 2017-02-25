#include"header.h"

void insert_at_middle()
{
	int track = 0;
	NODE *temp;
	NODE *traverse;
	temp = create();
	char ch_element[MAX];
	int element;
	
	if (head == NULL) {
		insert_at_begining();
	} 
	else {
		printf("\nEnter element: ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		element = is_valid(ch_element);

		traverse = head;
		while(traverse->link != NULL)  {
			traverse = traverse->link;
			track++;
		}
		track = (track / 2) + 1;
		traverse = head;
		while(--track)
			traverse = traverse->link;

		temp->link = traverse->link;
		traverse->link = temp;
		temp->data = element;
	}
}
