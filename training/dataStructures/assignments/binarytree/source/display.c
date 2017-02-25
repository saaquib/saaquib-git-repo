#include"header.h"

void pre_order(NODE *current)
{
		if ( current != NULL ) {
			printf("%d\t",current->data);
			pre_order(current->left);
			pre_order(current->right);
		}
}
void post_order(NODE *current)
{
		if ( current != NULL ) {
			post_order(current->left);
			post_order(current->right);
			printf("%d\t",current->data);
		}
}
void in_order(NODE *current)
{
		if ( current != NULL ) {
			in_order(current->left);
			printf("%d\t",current->data);
			in_order(current->right);
		}
}


