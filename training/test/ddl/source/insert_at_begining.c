#include"header.h"

void insert_at_begining(void)
{
//	create(n[count]);
	NODE *temp;
	temp = create();
	char ch_element[MAX];
	int element;
	
	printf("\nEnter element: ");
	fgets(ch_element,MAX,stdin);
	rem_ent(ch_element);
	//element = is_valid(ch_element);
	if(head == NULL)
	{
		temp->next = head;
		temp->prev = NULL;
		strcpy(temp->data, ch_element);
		head = temp;
		tail = temp;
		count++;
	}

	else
	{
		temp->next = head;
		temp->prev = NULL;
		strcpy(temp->data, ch_element);
		head->prev = temp;
		head = temp;
		count++;
	}
}
