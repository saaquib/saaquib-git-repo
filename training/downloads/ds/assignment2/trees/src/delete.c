//delete node fiunction

#include "header.h" //include header file

node *del(node *root)
{
	node *temp = NULL;
	char *str = NULL;
	int element;
	node *temp2;

	if ( NULL == (temp2 = (node *)malloc(sizeof(char)*MAX) ) ) {                 
        perror("malloc failed\n");                                              
        exit(0);                                                                
    } 
	
	if ( NULL == (temp = (node *)malloc(sizeof(char)*MAX) ) ) {
		perror("malloc failed\n");
		exit(0);
	}
	
	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX) ) ) {
		perror("malloc failed\n");
		exit(0);
	}
	printf("enter the element to be deleted\n");	
	fgets(str,MAX,stdin);
	
	element = atoi(str);
	temp2 = NULL;
	temp = root;
	while ( temp  != NULL ) {
		if ( element < temp -> data ){
			if ( (temp -> left) -> data == element) {
				temp2 = temp -> left;
				break;	
			}
			temp = temp -> left;
		} 
			
		else if ( element > temp -> data ){
			if ( (temp -> right) -> data == element ) {
				temp2 = temp -> right;
				break;
			}
		
			temp = temp -> right;
		}
		else {
			temp2 = root;
			break;
		}
	}
	if ( temp2 == NULL ) {
		printf("the element given is not there in th list\n");
		return root;
	}
	if ( temp2 -> left == NULL && temp2 -> right == NULL ) {
		if ( temp -> data > temp2 -> data )
			temp -> left = NULL;
		else
			temp -> right = NULL;
		return root;
	}
	
	if ( temp2 -> left != NULL && temp2 -> right == NULL ) {
		if ( temp -> data > temp2 -> data )
                        temp -> left = temp2 -> left;
                else
                        temp -> right = temp2 -> left;
                return root;
	}
	
	if ( temp2 -> left == NULL && temp2 -> right != NULL ) {
		if ( temp -> data > temp2 -> data )
                        temp -> left = temp2 -> right;
                else
                        temp -> right = temp2 -> right;
                return root;
	}
	/*temp = root;
	if ( temp2 == root ) {
		if ( temp -> left -> right != NULL ) {
			temp = temp -> left;
			while ( temp -> right != NULL )
				temp = temp -> right;
			root -> data =  temp -> right ->  data;
			temp -> right = temp -> right -> left;
		}	
			
		else {
			root -> data = root -> left -> data;
			root -> left = root -> left -> left;
		}
		return root;
			
	}*/
	
	if ( temp2 -> left != NULL && temp2 -> right != NULL ) {
		 if ( temp2 -> left -> right != NULL ) {
                        temp = temp2 -> left;
                        while ( temp -> right -> right != NULL )
                                temp = temp -> right;
                        temp2 -> data =  temp -> right ->  data;
                        temp -> right = temp -> right -> left;
                }
                      
                else {
                        temp2 -> data = temp2 -> left -> data;
                        temp2 -> left = temp2 -> left -> left;
                }
		return root;

        }
}

