#include "header.h"

NODE* create(void)
{
	int val;
	NODE* temp = (NODE *)malloc(sizeof(NODE));
	 
	if(temp == NULL)
		printf("node not created\n");

	else
	{	/*printf("enter tha value \n");
		scanf("%d",&val);
		temp->data = val;*/
		temp->next = NULL;
		temp->prev = NULL;
		
	}
	
	return temp;
}
