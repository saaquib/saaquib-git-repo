
#include<stdio.h>
#include<limits.h>
#include"c_pgm.h"


//1. using limits.h print range
#if 0 
int main()
{
	printf("%d\n",SCHAR_MIN);
	printf("%d\n",CHAR_BIT);
	printf("%d\n",SCHAR_MAX);
	printf("%d\n",UCHAR_MAX);
	printf("%d\n",CHAR_MIN);
	printf("%d\n",INT_MIN);
	printf("%d\n",INT_MAX);
	return 0;
}
#endif


//2. int out of bound 
#if 0

int main()
{
	int i=2147483650;
	printf("%d",i);
	return 0;
}
#endif


//3. storage classes
#if 1 

int ext_var;
static int stat_var2=1;

void fun1(void);
void fun2(void);

int main()
{
	register int reg_var;
	int k;
	ext_var=4;
	printf("\next_var in main : %d\n",ext_var);
	for(reg_var=1;reg_var<=3;reg_var++)
	{
		printf("\n______________________________________________");
		printf("\nreg_var in fun1() : %d",reg_var);
		fun1();
	}
	printf("\n______________________________________________");
	printf("\nstat_var2 in fun2() : %d",stat_var2);
        fun2();
	printf("\nstat_var2 in fun2() : %d",stat_var2);
	fun2();
	printf("\nstat_var2 in fun2() : %d",stat_var2);
	printf("\n______________________________________________");
	fun1();
	printf("\n");
	printf("\next_var in main : %d\n",ext_var);
	k=fun3();
	printf("\n%d\n",k);
	return 0;	
}

void fun1(void)
{
	auto int auto_var=1;
	static int stat_var=1;
	ext_var=5;
	printf("\nauto_var in fun1() : %d",auto_var);
	printf("\nstat_var in fun1() : %d",stat_var);
	printf("\nstat_var2 in fun1() : %d",stat_var2);
	printf("\next_var in fun1() : %d",ext_var);
	auto_var++;
	stat_var++;
	stat_var2++;
}

void fun2(void)
{	
	stat_var2++;
}

#endif


//4. operation on bits and converting number into 32bit bin format
#if 0
void showbits(int);
int main()
{
        int a = 5;
	int b = 3;
	int k;
	showbits(a);
	printf("\n");
	showbits(b);
	printf("\n");
	a>>2;
	showbits(a);
	printf("\n");
	b<<2;
 	showbits(b);
	printf("\n");
	k = a|b;
	showbits(k);
	printf("\n");
	k=a&b;
	showbits(b);
	printf("\n");
        k = a^b;
	showbits(k);
	printf("\n");
        return 0;
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
#endif


//5.  switch 
#if 0

int main()
{
	int a ;
	int b ;
	int c ;
	int d ;
	float e ;
	printf("\nEnter the numbers a and b: ");
	scanf("%d %d",&a,&b);
	printf("\n1. sum");
	printf("\n2. difference");
	printf("\n3. mul");
	printf("\n4. div");
	printf("\n5. mod");
	printf("\nEnter option: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1: d = a + b;
			printf("\nsum is : %d",d);
			break;
		case 2: d = a - b;
                        printf("\ndifference is : %d",d);
                        break;
		case 3: d = a * b;
                        printf("\nmul is : %d",d);
                        break;
		case 4: e = a / b;
                        printf("\ndiv is : %f",e);
                        break;
		case 5: d = a % b;
                        printf("\nmod is : %d",d);
                        break;
	}
	printf("\n");
	return 0;
}
#endif


//6. pre increment and post increment
#if 0
main()
{
	int i=1;
	printf("\nPre increment : %d",++i);
	printf("\npost increment : %d",i++);
	printf("\n%d",i);
	return 0;
} 

#endif
