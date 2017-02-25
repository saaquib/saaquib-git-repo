#include"header.h"

int search(int num)
{
	int position = 0;
	NODE *traverse;
	traverse = head;
	while(traverse->data != num)
	{
		traverse = traverse->link;
		position++;
	}
	return position;
}
