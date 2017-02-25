#include "header.h"

void insert(NODE *new)
{
	if(root == NULL)
	{
		root = MEM_CREATE;
		IS_MEM_ALLOC(root);
		root = new;
	} 
	else  {
		temp = MEM_CREATE;
		IS_MEM_ALLOC(temp);	
		temp = root;
   		while(1) {
			if( new->data > temp->data ) {
				if(temp->right == NULL) {
					temp->right = new;
					break;
				}
				else 
					temp = temp->right;
			} 
			else  { 
				if(temp->left == NULL) {
					temp->left = new;
					break;
				}
				else 
					temp = temp->left;
			} 
		}
	}
}
	
	
