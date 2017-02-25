#include <stdio.h> //include standard input output header    
                                                         
#include <stdlib.h> //include standard library
                                                            
#define MAX 64 //macro to define MAX value

//structure to define node                                                                 
typedef struct node {                                                           
        int data;                                                               
        struct node *left;                                                      
        struct node *right;                                                     
}node; 

node *insert( node *root);
	
void preorder(node *root);
	
void inorder(node *root);
	
void postorder(node *root);

node *del(node *root);

