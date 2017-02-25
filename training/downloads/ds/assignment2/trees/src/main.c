#include "header.h"

int main()
{
	int option;
	char *str = NULL;
	
	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX))) {
		printf ("malloc failed\n");
		exit(0);
	}
	
	node *root = NULL;
	while (1) {
	printf("1.INSERT\n2.PRE ORDER\n3.IN ORDER\n4.POST ORDER\n5.DELETE\n6.EXIT\n");
	printf("enter the option\n");
	
	if ( NULL == (fgets(str,MAX,stdin))) {
		printf ("entered wrong input\n");
		exit(0);
	}
	
	option = atoi(str);
	switch(option) {
		case 1:
				root = insert(root);
				break;

		case 2:
				if ( root == NULL ) {
					printf("no elements in the tree\n");
					break;
				}
				else  
				preorder(root);
				printf("\n");
				break;

		case 3:
				if ( root == NULL ) {
					printf ("no elements in the tree\n");
					break;
				}
				else
					inorder(root);
				printf("\n");
				break;

		case 4:
				if ( root == NULL ) {
					printf ( "no elements in the tree\n");
					break;
				}
				else
				postorder(root);
				printf("\n");
				break;
	
		case 5:
				del(root);
				break;
		case 6:
				return 0;
		
		default: 
				printf("enter correct input\n");
	}
	}
	return 0;
}
	
