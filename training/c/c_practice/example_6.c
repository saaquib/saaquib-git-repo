#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct emp                                                              
{                                                               
    char *n;                                            
    int age;                                    
};
int main()
{
	struct emp e1 = {"Dravid", 23};
	struct emp e2 = e1;
//	printf("\n%d",sizeof(e1));
//	printf("add e1: %p	\nadd e2: %p",&e1,&e2);
	printf("add e1.n : %p	\nadd e2.n: %p",e1.n,e2.n);
	e1.n = "Saaquib";
	 printf("add e1.n : %p   \nadd e2.n: %p",e1.n,e2.n);
//	printf("add e1.n : %p   \nadd e2.n: %p",&e1.n,&e2.n);
//	toupper(e2.n);
	printf("%s\n", e1.n);
	//	printf("%s\n", e2.n);
	return 0;
}
