#include "header.h"

void postorder(node *root)
{
	if ( root != NULL ) {
		postorder(root -> left);
		postorder(root -> right);
		printf("%d\t",root -> data);
	}
}
