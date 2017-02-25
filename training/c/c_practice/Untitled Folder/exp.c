#include<stdio.h>
extern void showbits(int);
int shift_s_d(int n,int s,int d);
int main()
{
	int num;
	int s;
	int d;
	int sres;
	int dres;
	int res;	
	int fin1;
	int fin2;
	int fin3;
	
	printf("\nEnter the number: ");
	scanf("%d",&num);
	
	showbits(num);
	printf("\n");
	
	printf("\nEnter the source bit: ");
        scanf("%d",&s);

	printf("\nEnter the destination bit: ");
        scanf("%d",&d);

	sres = shift_s_d(num,s,d); 

	dres = shift_s_d(num,d,s);

	res = sres | dres;

	fin1=(~(1<<(s-1)))&num;
	fin2=(~(1<<(d-1)))&num;
	
	num=fin1&fin2;
	
	fin3=num|res;
	showbits(fin3);
	return 0;
}

int shift_s_d(int n,int s,int d)
{
	int res1, res2, res3;
	res1 = (1<<s-1) & n; 
        res2 = res1 >> s-1;
        res3 = res2 << d-1;
        return res3;
}
void showbits(int c)
{
        int i;
        int count=0;
        i=sizeof(int)*8;
        for(;i>0;i--)
        {
                printf("%d",(1&(c>>(i-1))));
                count++;
                if(count%8==0)
                        printf(" ");

        }
}

