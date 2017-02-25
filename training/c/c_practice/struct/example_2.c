#include<stdio.h>
struct batch
{
	int x;
	char ch;
};
int main()
{
	struct batch e1, *e2;
	e1.x = 1;
	e1.ch = 'a';
	e2 = e1;
	printf("%d ",e1->)
