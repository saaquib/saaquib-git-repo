#include"header.h"

void insert_at_given_position(int pos)
{
//	create(n[count]);
	NODE *temp;
	NODE *traverse;
	NODE *previous;
	temp = create();
	char ch_element[MAX];
	int element;
	
	traverse = head;
	if(pos < count)  {
		if(pos == 0)
			insert_at_begining();

		else
		{
			printf("\nEnter element: ");
			fgets(ch_element,MAX,stdin);
			rem_ent(ch_element);
			//element = is_valid(ch_element);
	
			while(pos--) {
				previous = traverse;
				traverse = traverse->next;
			}
			temp->next = traverse;
			temp->prev = previous;
			previous->next = temp;
			traverse->prev = temp;
			strcpy(temp->data, ch_element);
			count++;	
/*			temp->next = previous->next;
			previous->next = temp;
			traverse->prev = temp;
			strcpy(temp->data, ch_element);
			count++;
*/			if (pos == count - 1)
				tail = temp;
		}
	}
	else
		printf("\n no such position");

}




