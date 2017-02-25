#include<stdio.h>
extern void showbits(int);			//converts decimal to binary
extern int getsbit(int num, int s);		//get the source bit
extern int shift(int n, int s, int d);		//shifts s bit to d position
extern int get_r_bits(int x, int n, int p);
// 1. Given 2 bit positions d and s in a number n, swap the bit values between sand d. int bit_swap (int n, int s, int d); where n is the number, s is the source bit position, d is the destination bit position.

#if 0
#include<stdio.h>
extern void showbits(int);
int bit_swap(int n, int s, int d);

int main()
{
        int num;
        int s;		//source bit
        int d;		//destination bit
        
        printf("\nEnter the number: ");
        scanf("%d",&num);

        showbits(num);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%d",&s);

        printf("\nEnter the destination bit: ");
        scanf("%d",&d);
   
        showbits(bit_swap(num, s, d));
    	printf("\n");
	return 0;
}

int bit_swap(int n, int s, int d)
{
    
        return (shift(n, s, d) | shift(n, d, s)) | (((~(1 << (s-1))) & n) & ((~(1 << (d-1))) & n));
}

#endif

#if 0

int main()
{
        int snum;
	int dnum;
        int s;
        int d;

        printf("\nEnter the snum: ");
        scanf("%d",&snum);

        showbits(snum);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%d",&s);
	
	printf("\nEnter the dnum: ");
        scanf("%d",&dnum);
	
	showbits(dnum);
        printf("\n");

        printf("\nEnter the destination bit: ");
        scanf("%d",&d);


	showbits(((~(1 << (s-1))) & snum) | (shift(getsbit(dnum, d), d, s)));
	printf("\n");

	showbits(((~(1 << (d-1))) & dnum) | (shift(getsbit(snum, s), s, d)));
	printf("\n");

	return 0;
}

#endif

#if 0
int bit_copy(int snum, int dnum, int n, int s, int d);
int main()
{
	int snum, s, dnum, d, n,s1,s2,d1, source, dest,final;
	printf("\nEnter the snum: ");
        scanf("%d",&snum);

        showbits(snum);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%d",&s);
        
        printf("\nEnter the dnum: ");
        scanf("%d",&dnum);
        
        showbits(dnum);
        printf("\n");

        printf("\nEnter the destination bit: ");
        scanf("%d",&d);
	
	printf("\nEnter the number of  bits: ");
        scanf("%d",&n);

	s1=get_r_bits(snum, s, n);
		
	s2 = s1 & snum;
	source=shift(s2,s-n,d-1);	
	showbits(source);
	printf("\n");
	
	d1=get_r_bits(dnum, d, n);
	showbits(~d1);
	printf("\n");
	dest = (~ d1) & dnum;
	showbits(dest);
	printf("\n");
		
	final = source | dest;
	showbits(final);
        printf("\n");
	
	return 0;
}


#endif

#if 0  
int even_bit_toggle(int num);
int odd_bit_toggle(int num);
int main()
{
	int num;
	printf("\nEnter the num: ");
        scanf("%d",&num);
	showbits(num);
	printf("\n");

	showbits(even_bit_toggle(num));
	printf("\n");
	
	showbits(odd_bit_toggle(num));
        printf("\n");

	return 0;
}

int even_bit_toggle(int num)
{
	int i;
	for(i=0;i<=31;i++)
       	{
               	num = num ^ (1<<i);
		i++;
        }
        	return num;
}

int odd_bit_toggle(int num)
{
        int i;
        for(i=1;i<=31;i++)
        {
                num = num ^ (1<<i);
		i++;     
        }
                return num;
}
#endif

#if 0
#define bit_ts(num ,pos) (num | (1 << pos-1) )
#define bit_tcs(num,s,c,t) ((num|(1<<s-1)) ^ (num & (~ (1 << c-1))) ^ num ^ (1 << t-1)) 
int main()
{
	int num, pos;
	printf("\nEnter the num: ");
        scanf("%d",&num);

        showbits(num);
        printf("\n");
        
        printf("\nEnter the bit: ");
        scanf("%d",&pos);

	showbits(bit_ts(num,pos));
	printf("\n");

	showbits(bit_tcs(num,5,1,30));
        printf("\n");

	return 0;
}

#endif

#if 0 
unsigned int left_rotate_bits (unsigned int num);
unsigned int right_rotate_bits (unsigned int num);
unsigned int left_rotate_n_bits (unsigned int num, int n);
unsigned int right_rotate_n_bits (unsigned int num, int n);
int main()
{
	int num, pos;
        printf("\nEnter the num: ");
        scanf("%d",&num);

        showbits(num);
        printf("\n");
        
        printf("\nEnter the bit: ");
        scanf("%d",&pos);

	printf("\nleft rotate");
	showbits(left_rotate_bits(num));
	printf("\n");
	
	printf("\nright rotate");
	showbits(right_rotate_bits(num));
        printf("\n");
	
	printf("\nleft rotate for n bits");
	showbits(left_rotate_n_bits(num, pos));
        printf("\n");

	printf("\nright rotate for n bits");
	showbits(right_rotate_n_bits(num,pos));
        printf("\n");

	return 0;
}

unsigned int left_rotate_bits (unsigned int num)
{
	return (((1 << 31 ) & num) | (num << 1));
}

unsigned int right_rotate_bits (unsigned int num)
{
	return ((num & 1) << 31) | (num >> 1);
}

unsigned int left_rotate_n_bits (unsigned int num, int n)
{
	return ((num & (~(~0 >> n))) >> 31 - n) | (num << n);
}

unsigned int right_rotate_n_bits (unsigned int num, int n)
{
	return (((~(~0 << n)) & num) << 31 - n) | (num >> n);
}

#endif

#if 0
int count_bit_set(int num);
int count_bit_clear(int num);
int main()
{
	int num;
	printf("\nEnter the num: ");
        scanf("%d",&num);
	showbits(num);
	printf("\n");
	printf("\n%d",count_bit_set(num));
	printf("\n");
	
	printf("\n%d",count_bit_clear(num));
        printf("\n");
	return 0;
}

int count_bit_set(int num)
{
	int i, count = 0;
	for(i=0;i<=31;i++)
	{
		(num & (1 << i)) ? count++ : count; 
	}
	return count;
}
int count_bit_clear(int num)
{
	int i, count = 0;
        for(i=0;i<=31;i++)
        {
                (num & (1 << i)) ? count : count++; 
        }
        return count;
}
#endif

#if 0
int cnt_leading_set_bits(int num);
//int cnt_leading_cleared_bits(int num);
//int cnt_trailing_cleared_bits(int num);
//int cnt_trailing_set_bits(int num);
int main()
{
	int num;
        printf("\nEnter the num: ");
        scanf("%d",&num);
        showbits(num);
        printf("\n");
	
	printf("\nleading set ");
        printf("\n%d",cnt_leading_set_bits(num));
        printf("\n");	
	
/*	printf("\nleading clear ");
	printf("\n%d",cnt_leading_cleared_bits(num));
        printf("\n");

	printf("\ntrailing clear ");
	printf("\n%d",cnt_trailing_cleared_bits(num));
        printf("\n");

	printf("\ntrailing set ");
	printf("\n%d",cnt_trailing_set_bits(num));
        printf("\n"); */
	return 0;
}

int cnt_leading_set_bits(int num)
{
	int count = 32, i;
	for(i=0; i <= 31; i++)
	{
		int k = (num & ((1 << 31) >> i));
		if(k=!0)
			break;
		else
			count--;
	}
	return count;
}

/*int cnt_leading_cleared_bits(int num)
{
	int count = 32, i;
	for(i=0; i <= 31; i++)    
	{
		int k=(num & ((1 << 31) >> i));
		if(k=!0)
			count--;
	else
		 break;
	}
        return count;
}

int cnt_trailing_cleared_bits(int num)
{
	int count = 1, i;
	for(i=0; i <= 31; i++)
	{
		int k = (num & (1 << i));
	        if(k=!0)
			count++;
		else
			 break;
	}
        return count;
}

int cnt_trailing_set_bits(int num)
{
	int count = 1, i;
        for(i=0; i <= 31; i++)
	{
		int k=(num & (1 << i));
        	if(k=!0)
			count++;
		else
			break;
	}
        return count;
}
*/
#endif
#if 0
int main()
{
        int num;
        int s;          //source bit
        int d;          //destination bit
        
        printf("\nEnter the number: ");
        scanf("%d",&num);

        showbits(num);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%d",&s);

        printf("\nEnter the destination bit: ");
        scanf("%d",&d);
	
	showbits(get_r_bits(num, s, d));
	printf("\n");
	return 0;
}
#endif

#if 0
#define getbits(x, n, p) ((x & ((~0 << (31-n)) >> 31-p)) >> p-n)
int main()
{
	int x;
        int n;          //source bit
        int p;          //destination bit
        
        printf("\nEnter the number: ");
        scanf("%d",&x);

        showbits(x);
        printf("\n");
        
        printf("\nEnter the number of bits: ");
        scanf("%d",&n);

        printf("\nEnter the position: ");
        scanf("%d",&p);
        
	showbits(getbits(x, n, p));
	return 0;

}
#endif

#if 0
int invert(int x, int n, int p);
int main()
{
	int x;
        int n;          //source bit
        int p;          //destination bit
        
        printf("\nEnter the number: ");
        scanf("%d",&x);

        showbits(x);
        printf("\n");
        
        printf("\nEnter the number of bits: ");
        scanf("%d",&n);

        printf("\nEnter the position: ");
        scanf("%d",&p);
 	
	showbits(invert(x, n, p));
	return 0;
}
int invert(int x, int n,int p)
{
	return (x ^ (~(~0 << n ) << (p - n)));
}
#endif

#if 1
int setbits(int x, int p, int n, int y);
int main()
{
	int x;
        int n;          //source bit
        int p;          //destination bit
	int y;
        
        printf("\nEnter the number x: ");
        scanf("%d",&x);

        showbits(x);
        printf("\n");
        
        printf("\nEnter the number of bits: ");
        scanf("%d",&n);

        printf("\nEnter the position: ");
        scanf("%d",&p);
        
	printf("\nEnter the number y: ");
        scanf("%d",&y);
	showbits(x);
        printf("\n");

        showbits(setbits(x, n, p, y));
        return 0;

}
int setbits(int x, int p, int n, int y)
{
	return ((y & (~(~0 << n ))) << (p-n) | (x & (~(~(~0 << n)) << (p-n))));
}
#endif
