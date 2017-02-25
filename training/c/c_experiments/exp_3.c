#include<stdio.h>
#include<string.h>
#if 0 
int main()
{
	char c= '1';

	int i = 0;
	int j;
	printf("%d\n",c);
	if(5-printf("hello"))
		printf("hello");
	else
		printf("world");

	switch(i)
	{
	case '0' : printf("\n global");
		break;
	case j : printf("\n jj");
		break;
	
}
	return 0;



}

#endif

#if 0

int main()
{
	int a[5] = {0, 22, 63, 54, 58};
	printf("\n add of a:  %p",a);
	printf("\n add of array: %p",&a);
	
	printf("\n add of next array: %p",(&a)+1);
	printf("\n add of 1st ele: %u", a+1);
		printf("\n value at 1st ele: %d", *(a+1));
	
	printf("\n add of 2nd ele: %p", a+2);
	printf("\n value at 2nd ele:  %d", *(a+2));

	printf("\n add of 3rd ele: %p", a+3);
        printf("\n value at 3rd ele:  %d", *(a+3));

        printf("\n add of 4th ele: %p", a+4);
        printf("\n value at 4tht ele:  %d", *(a+4));
	
	printf("\n %p",(&a[4]-&a[1]));
	printf("\n %p",((*(a+4))-(*(a))));
	*(a+3) = 5;
	printf("\n %d",a[3]);
	return 0;
	
}

#endif


#if 1

int main()
{
	char ch[10] = "saaquib";
	char ch2[10];
	fgets(ch2);
	printf("\n%s",ch2);
	printf("\n%s",ch);
	printf("\n%c",*(ch+3));
	printf("\n%s",ch+3);
	
	return 0;

}
#endif
