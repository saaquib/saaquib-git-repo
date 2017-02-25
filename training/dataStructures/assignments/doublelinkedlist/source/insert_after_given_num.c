#include"header.h"

void insert_before_given_num(int num)
{
    int track = 0;
	NODE *temp;
	NODE *traverse;
	NODE *previous;
	temp = create();
	char ch_element[MAX];
	int element;
	
	traverse = head;
	if (head == NULL) {
		printf("\n List is empty");
	}
	else {
		while((traverse->data != num) && (traverse->next != NULL)) {
			previous = traverse;
			traverse = traverse->next;
			track++;
		}
		if (track == 0) {
			insert_at_begining();
			return;
		}
		printf("\nEnter element: ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		element = is_valid(ch_element);
	
		if (traverse->data == num) {
			temp->next = previous->next;
			previous->next = temp;
			traverse->prev = temp;
			temp->data = element;
			count++;
		}
		else {
			printf("\nNot found");
		}
	}
}
