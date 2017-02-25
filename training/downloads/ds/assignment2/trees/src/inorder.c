#include "header.h"

void inorder(node *root)
{
	if ( root != NULL ) {
		inorder(root -> left);
		printf("%d\t",root -> data);
		inorder(root -> right);
	}
}
	

