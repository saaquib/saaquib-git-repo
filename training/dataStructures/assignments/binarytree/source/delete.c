#include "header.h"
void delete(int num)
{
  NODE *prev = MEM_CREATE;
	IS_MEM_ALLOC(prev);
/*  NODE *extra = MEM_CREATE;
	IS_MEM_ALLOC(extra);
  NODE *temp2 = MEM_CREATE;
	IS_MEM_ALLOC(temp2);
*/
  temp = root;

  while(temp->data != num) {
	  	if( temp->data < num ) {
        prev = temp;
        temp = temp->right;
       }
       else {
        prev = temp;
        temp = temp->left;
       }
  }
  printf("\nprev: %d",prev->data);
  printf("\ntemp: %d",temp->data);
  printf("\ntemp->left: %d",(temp->left)->data);
 
	if((temp->left == NULL) && (temp->right != NULL)) {
		if(temp->data < prev->data) {
			prev->left = temp->right;
			free(temp);
		}
		else {
			prev->right = temp->right;
			free(temp);
		}
	}
	else {//if((temp->left != NULL) && (temp->right == NULL)) {
		if(temp->data < prev->data) {
			prev->left = temp->left;
			free(temp);
		}
		else {
			prev->right = temp->left;
			free(temp);
		}
	}
}/*	if ( (temp->left == NULL) && (temp->right == NULL) ) {
		if(temp->data < prev->data) {
			prev->left = NULL;
			free(temp);
		}
		else {
			prev->right = NULL;
			free(temp);
		}
	  }
  }*/
/* else if ( temp->left == NULL ) {
	  extra = temp;
	  temp = temp->right;
	  free(extra);
	  return;
  } else if ( temp->right == NULL ) {
	  extra = temp;
	  temp = temp->left;
	  free(extra);
	  return;
  }
  else {
	  extra = temp->left;
	  while ( extra->right != NULL ) {
		  extra = extra->right;
	  }
	  prev->right = extra;
	  extra->left = temp->left;
	  free(temp);
	  return;
  }
}
  

 	 
  
    
  prev->left = temp->left;
  prev = prev->left;
  prev->right = temp->right;*/

