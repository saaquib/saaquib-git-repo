#include<stdio.h>
#if 0
void showbits(int);
int main()
{
	int a,b,c,d;
	a=0xa7;
	showbits(a);
	printf("\n");
	b=1&a;
	c=b<<31;
	d=c|(a>>1);
	//d=c|(a<<31);
	showbits(d);
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
#if 1
int getbits(int x,int n,int p);
void showbits(int);
int main()
{
	int x,n,p,res;
	printf("\nenter x,n,p: ");
	scanf("%d%d%d",&x,&n,&p);
	printf("\n");
	showbits(x);
	res=getbits(x,n,p);
	printf("\n");
	showbits(res);
	printf("\n");
	return 0;
}
int getbits(int x,int n,int p)
{
	int res1,res2,res3;
	res1=x>>p;
	res2=~((~0)<<n);
	res3=res1&res2;
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
#endif

#if 0
int getbits(int x,int n,int p);
void showbits(int);
int main()
{
        int x,n,p,res;
        printf("\nenter x,n,p: ");
        scanf("%d%d%d",&x,&n,&p);
        printf("\n");
        showbits(x);
        res=getbits(x,n,p);
        printf("\n");
        showbits(res);
        printf("\n");
        return 0;
}
int getbits(int x,int n,int p)
{
        int res1,res2,d,e,f,a,b,c;
	a = (~0)<<p;
	c = ~a;
	res2 = x&c;
	d = (~0)<<n;
        e = ~d;
	f = e<<(p-n);
	res1 = f&res2;
        return res1;
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

