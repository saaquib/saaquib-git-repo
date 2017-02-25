#include "header.h"

NODE* create(void)
{
	char ch_num[MAX];
	int num;
	NODE* temp = MEM_CREATE;
	IS_MEM_ALLOC(temp);
	 
	printf("\nenter num: ");
	fgets(ch_num,MAX,stdin);
	rem_ent(ch_num);
	num = is_valid(ch_num);

	temp->data = num;
	temp->left = NULL;
	temp->right = NULL;
		
	return temp;
}
