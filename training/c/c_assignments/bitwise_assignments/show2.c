#include<stdio.h>
void showbits(num);
int main()
{
	int num = 16;
	
	showbits(num);
	return 0;
}
void showbits(int c)
{       
	int i;
        for( i = 31; i >= 0; i--)
        {
                printf("%d",(1 & ( c >> i)));
                if(i%8==0)
                        printf(" ");
                
        }
}
