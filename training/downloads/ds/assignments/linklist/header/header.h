#include <stdio.h>
#include <stdlib.h>

#define MAX 64

typedef struct list {
	int data;
	struct list *next;
}sl;
// insert catalog function
sl *insert(sl *head);

//all options in insert functions
sl *insertbeg(sl *head);
sl *insertend(sl *head);
sl *insertmid(sl *head);
sl *insertat(sl *head);
sl *insertafter(sl * head);
sl *insertbef(sl *head);
sl *insertaftnum(sl *head);
sl *insertbefnum(sl *head);

//delete catalog function
sl *del(sl *head);

//all options in delete functions
sl *deletebeg(sl *beg);
sl *deleteend(sl *head);
sl *deletemid(sl *head);
sl *deleteat(sl *head);
sl *delafter(sl *head);
sl *delbef(sl *head);
sl *delbefnum(sl *head);
sl *delaftnum(sl *head);
//display function
void display(sl *head);

