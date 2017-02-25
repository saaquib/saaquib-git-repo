#include"header.h"

void insert_at_end(void)
{
	NODE *temp;
	NODE *traverse;
	NODE *prev;
//	create(n[count]);
  	temp = create();

	char ch_element[MAX];
	int element;

	traverse = head;	

	if(head == NULL)	
		insert_at_begining();
	else
	{
		printf("\nEnter element: ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		//element = is_valid(ch_element);

	
		while(traverse->next != NULL) {
			prev = traverse;
			traverse = traverse->next;
		}
		traverse->next = temp;
		temp->next = NULL;
		temp->prev = traverse;
		strcpy(temp->data, ch_element);
		//prev -> next = temp;
		tail = temp;
		count++;
	}
}
