#include<stdlib.h>                                                              
#include<string.h>                                                              
#include<stdio.h>                                                                                
struct node{                                                                    
        int data;                                                               
        struct node *next;                                                      
        struct node *prev;                                                      
       };                                                                       
                                                                                
typedef struct node * cdll;                                                      
cdll head;                                                                       
                                                                                
#define DYN (cdll)malloc(sizeof(cdll))                                            
#define MAX 100                                                                 
                                                                                
//int count(sll);                                                                 
                                                                                
cdll insert_node(cdll);                                                           
                                                                                
void display(cdll);                                                              
                                                                                
cdll delet_node(cdll);  
