#include <stdio.h>                                                              
#include <stdlib.h>                                                             
                                                                                
#define MAX 5                                                                  
                                                                                
int queue[MAX];                                                                 
int front;                                                                      
int rear;
int count;                                                                       
                                                                                
void enqueue(int);                                                              
int dequeue();                                                                  
void display(); 
