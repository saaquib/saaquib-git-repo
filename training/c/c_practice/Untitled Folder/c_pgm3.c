#include<stdio.h>
int main()
{
	int i;
	int n;
	int count=0;
	printf("\nenter the number: ");
	scanf("%d",&n);
        i=sizeof(int)*8;
	for(;i>0;i--)
        {
                printf("%d",(1&(n>>(i-1))));
		count++;
		if(count%8==0)
			printf(" ");   
        }
	return 0;
}

