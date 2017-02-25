#include "header.h"

void preorder(node *root)
{
	if ( root != NULL ) {
		printf ("%d\t",root -> data);
		preorder(root -> left);
		preorder(root -> right);
	}
}
