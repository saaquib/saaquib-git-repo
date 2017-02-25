// SAAQUIB HUSSAIN PODIKAR
// employment id: 30860
// e-mail id: saaquib123@gmail.com

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

extern void showbits(int);			//converts the decimal into  binary
extern int getsbit(int num, int s);		//get the source bit
extern int shift(int n, int s, int d);		//shifts s bit to d position
extern int get_r_bits(int x, int n, int p);     //get the n bits of x set from position p
extern getbits(int x, int n, int p);            // get n bits of x from position p
extern int is_valid(char *);

// 1. Given 2 bit positions d and s in a number n, swap the bit values between sand d. int bit_swap (int n, int s, int d); where n is the number, s is the source bit position, d is the destination bit position.

#if 0

int bit_swap(int n, int s, int d);

int main()
{
	char ch[10];	//the input number
        int num;	//the input number
        int s;		//source bit
        int d;		//destination bit
        
        printf("\nEnter the number: ");
        scanf("%s",ch);
	
	num = is_valid(ch);
	
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

// 2. Given the bit position s in number snum and the bit position d in number dnum, swap bit values between s and d.

#if 0

int main()
{
        char ch_snum[10];
	char ch_dnum[10];
	char ch_s[10];
	char ch_d[10];
	int snum;	//source input number
	int dnum;	//destination input number
        int s;		//source bit
        int d;		//destination bit

        printf("\nEnter the snum: ");
        scanf("%s",ch_snum);

	snum = is_valid(ch_snum);
        showbits(snum);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%s",ch_s);
	
	s = is_valid(ch_s);

	printf("\nEnter the dnum: ");
        scanf("%s",ch_dnum);
	dnum = is_valid(ch_dnum);
	
	showbits(dnum);
        printf("\n");

        printf("\nEnter the destination bit: ");
        scanf("%s",ch_d);

	d = is_valid(ch_d);

	showbits(((~(1 << (s-1))) & snum) | (shift(getsbit(dnum, d), d, s)));
	printf("\n");

	showbits(((~(1 << (d-1))) & dnum) | (shift(getsbit(snum, s), s, d)));
	printf("\n");

	return 0;
}

#endif

// 3. Write a function bit_copy (int snum, int dnum, int n, int s, int d) which copies n bits (right adjusted) from bit position s in snum to bit position d in dnum.

#if 0

int bit_copy(int snum, int dnum, int n, int s, int d);

int main()
{
	char ch_snum[10];
        char ch_dnum[10];
        char ch_s[10];
        char ch_d[10];
	char ch_n[10];
        int snum;       //source input number
        int dnum;       //destination input number
        int s;          //source bit
        int d;          //destination bit
	int n;

        printf("\nEnter the snum: ");
        scanf("%s",ch_snum);

        snum = is_valid(ch_snum);
        showbits(snum);
        printf("\n");
        
        printf("\nEnter the source bit: ");
        scanf("%s",ch_s);
        
        s = is_valid(ch_s);

        printf("\nEnter the dnum: ");
        scanf("%s",ch_dnum);
        dnum = is_valid(ch_dnum);
        
        showbits(dnum);
        printf("\n");

        printf("\nEnter the destination bit: ");
        scanf("%s",ch_d);

        d = is_valid(ch_d);
	
	printf("\nEnter the number of  bit: ");
        scanf("%s",ch_n);

        n = is_valid(ch_n);

	showbits(bit_copy(snum, dnum, n, s, d));

	return 0;
}

int bit_copy(int snum, int dnum, int n, int s, int d)
{
	return (((~(get_r_bits(dnum, d, n))) & dnum ) | (getbits(snum, n, s) << (d-n)));
}

#endif

// 4. Write the following functions which will toggle even bits and odd bits respectively in a given number
//  a. Toggle even bit: int even_bit_toggle (int num);
//  b. Toggle odd bit: int odd_bit_toggle (int num);

#if 0  

int even_bit_toggle(int num);
int odd_bit_toggle(int num);

int main()
{
	char ch_num[10];
	int num;	//input number

	printf("\nEnter the num: ");
        scanf("%s",ch_num);

	num = is_valid(ch_num);
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

// 5. Write a macro to test and set a bit position in a number. 
//  a. #define bit_ts (num, pos)

#if 0

#define bit_ts(num ,pos) (num | (1 << pos-1) )
#define bit_tcs(num,s,c,t) ((num|(1<<s-1)) ^ (num & (~ (1 << c-1))) ^ num ^ (1 << t-1)) 

int main()
{
	char ch_num[10];
	char ch_pos[10];
	int num;	//input number
	int  pos;	//position

	printf("\nEnter the num: ");
        scanf("%s",ch_num);
	
	num = is_valid(ch_num);
        showbits(num);
        printf("\n");
        
        printf("\nEnter the bit: ");
        scanf("%s",ch_pos);
	pos = is_valid(ch_pos);

	showbits(bit_ts(num,pos));
	printf("\n");

	showbits(bit_tcs(num,5,1,30));
        printf("\n");

	return 0;
}

#endif

//6. Write the following functions

//  a. unsigned int left_rotate_bits (unsigned int num);
//which will return the number, resulted by left rotating the number num

//  b. unsigned int right_rotate_bits (unsigned int num);
//which will return the number, resulted by right rotating the number num

//  c. unsigned int left_rotate_n_bits (unsigned int num, int n);
//which will return the number, resulted by left rotating the number num by n bits

//  d. unsigned int right_rotate_n_bits (unsigned int num, int n);
//which will return the number, resulted by right rotating the number num by n bits

#if 0

unsigned int left_rotate_bits (unsigned int num);
unsigned int right_rotate_bits (unsigned int num);
unsigned int left_rotate_n_bits (unsigned int num, int n);
unsigned int right_rotate_n_bits (unsigned int num, int n);

int main()
{
	char ch_num[10];
	char ch_pos[10];
	int num;	//input number 
	int pos;	//input position 

        printf("\nEnter the num: ");
        scanf("%s",ch_num);

	num = is_valid(ch_num);
        showbits(num);
        printf("\n");
        
        printf("\nEnter the number of bits: ");
        scanf("%s",ch_pos);
	num = is_valid(ch_pos);

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

//7. Write the following functions which will count the number of bits set and number of bits cleared in the given number num respectively
// a. count_bit_set (int num);
// b. count_bit_clear (int num);

#if 0

int count_bit_set(int num);
int count_bit_clear(int num);

int main()
{
	char ch_num[10];
	int num;	//input number

	printf("\nEnter the num: ");
        scanf("%s",ch_num);

	num = is_valid(ch_num);
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
	int i;
	int  count = 0;

	for(i=0;i<=31;i++)
	{
		(num & (1 << i)) ? count++ : count; 
	}
	return count;
}

int count_bit_clear(int num)
{
	int i;
	int  count = 0;

        for(i=0;i<=31;i++)
        {
                (num & (1 << i)) ? count : count++; 
        }
        return count;
}
#endif

//8. Write the following functions
//  a. int cnt_leading_set_bits (int num) returns the number of leading set bits
//  b. int cnt_leading_cleared_bits (int num) returns the number of leading cleared bits
//  c. int cnt_trailing_cleared_bits (int num) returns the number of trailing cleared bits
//  d. int cnt_trailing_set_bits (int num) returns the number of trailing set bits

#if 0
int cnt_leading_set_bits(int num);
int cnt_leading_cleared_bits(int num);
int cnt_trailing_cleared_bits(int num);
int cnt_trailing_set_bits(int num);

int main()
{
	char ch_num[10];
	int num;	//input number

        printf("\nEnter the num: ");
        scanf("%s",ch_num);

	num = is_valid(ch_num);
        showbits(num);
        printf("\n");
	
	printf("\nleading set ");
        printf("\n%d",cnt_leading_set_bits(num));
        printf("\n");	
	
	printf("\nleading clear ");
	printf("\n%d",cnt_leading_cleared_bits(num));
        printf("\n");

	printf("\ntrailing clear ");
	printf("\n%d",cnt_trailing_cleared_bits(num));
        printf("\n");

	printf("\ntrailing set ");
	printf("\n%d",cnt_trailing_set_bits(num));
        printf("\n");

	return 0;
}

int cnt_leading_set_bits(int num)
{
	int count = 0;
	int  i;

	for(i=0; i <= 31; i++)
	{
		if(num & ((1 << 31) >> i))
			count++;
		else
			break;
	}
	return count;
}

int cnt_leading_cleared_bits(int num)
{
	int count = 0;
	int  i;

        for(i=0; i <= 31; i++)
        {
                if(num & ((1 << 31) >> i)) 
                        break; 
                else 
                        count++;
        }
        return count;
}

int cnt_trailing_cleared_bits(int num)
{
	int count = 0;
	int i;

        for(i=0; i <= 31; i++)
        {
                if(num & (1 << i))
                        break;
                else
                        count++;
        }
        return count;
}

int cnt_trailing_set_bits(int num)
{
	int count = 0;
	int i;
        
	for(i=0; i <= 31; i++)
        {
                if(num & (1 << i))
                        count++;
                else
                        break;
        }
        return count;
}

#endif

//11. Write a function invert (x,p,n) that returns x with n bits that begin at position p inverted, leaving others unchanged.

#if 0
int invert(int x, int n, int p);

int main()
{
	char ch_x[10];
	char ch_n[10];
	char ch_p[10];
	int x;		//input number
        int n;          //source bit
        int p;          //destination bit
        
        printf("\nEnter the number: ");
        scanf("%s",ch_x);

	x = is_valid(ch_x);
        showbits(x);
        printf("\n");
        
        printf("\nEnter the number of bits: ");
        scanf("%s",ch_n);
	n = is_valid(ch_n);

        printf("\nEnter the position: ");
        scanf("%s",ch_p);
 	p = is_valid(ch_p);

	showbits(invert(x, n, p));

	return 0;
}

int invert(int x, int n,int p)
{
	return (x ^ (~(~0 << n ) << (p - n)));
}

#endif

//9. Write macros for the following using bitwise operations:
//   a. To find maximum and minimum of 2 numbers
//   b. To clear right most set bit in a number
//   c. To clear left most set bit in a number
//   d. To set right most cleared bit in a number
//   e. To set left most cleared bit in a number
//   f. To set bits from bit position ‘s’ to bit position ‘d’ in a given number and clear rest of the bits
//   g. To clear bits from bit position ‘s’ to bit position ‘d’ in a given number and set rest of the bits
//   h. To toggle bits from bit position ‘s’ to bit position ‘d’ in a given number

#if 1

#define max(a,b) 						\
	int z; 							\
	int cou = 31; 						\
	for(z=31;z >=0; z--){					\
		if((a ^ b) & (1 << z)){ 			\
			if(a & (1 << cou)){ 			\
				printf("%d",a); 		\
				break; }			\
			else { 					\
				printf("%d",b); 		\
				break;	}			\
		} \
		else cou--; \
} 

#define clr_rt_st_bit(num) 					\
	int i; 							\
	for(i=0; i<=31;i++)    					\
	{	if(num & (1 << i)) 				\
			{	showbits((~(1 << i) & num)); 	\
				break;				\
			}					\
	}							\

#define clr_lt_st_bit(num)  					\
	int j; 							\
	for(j=0; j<=31;j++)    					\
	{       if(num & (1 << (31-j))) 			\
        	        {       showbits((~(1 << (31-j)) & num)); \
                	        break;  			\
	                }       				\
	}       						\

#define set_rt_clr_bit(num) 					\
	int k; 							\
	for(k=0; k<=31;k++)    					\
	{       if(!(num & (1 << k))) 				\
	                {					\
				showbits((1 << k) | num); 	\
				break;				\
			}         				\
	}       						\

#define set_lt_clr_bit(num)  					\
	int l; 							\
	for(l=0; l<=31;l++)    					\
	{       if(!(num & (1 << (31-l)))) 			\
	                {       showbits((1 << (31-l)) | num); 	\
	                        break;  			\
	                }       				\
	}       						\

#define set_s_d(num, s, d) ((~((~0) << ((s > d) ? (s - 1 ): (d - 1 )))) & ((~0) << ((s > d) ? d :  s )))  
	
#define clr_s_d(num, s, d) (~((~((~0) << ((s > d) ? (s - 1 ): (d - 1 )))) & ((~0) << ((s > d) ? d : s ))))

#define tog_s_d(num, s, d) (num ^ ((~((~0) << ((s > d) ? (s - 1 ): (d - 1 )))) & ((~0) << ((s > d) ?  d : s ))))

int main()
{
	char ch_a[10];	//first variable
	char ch_b[10];  //second variable
	char ch_num[10];  
	int a;		//source bit
	int b;		//destination bit
	int num;

	printf("\nEnter the number a: ");
        scanf("%s",ch_a);
	a = is_valid(ch_a);

	printf("\nEnter the number b: ");
        scanf("%s",ch_b);
	b = is_valid(ch_b);

	printf("\nEnter the number: ");
        scanf("%s",ch_num);
	num = is_valid(ch_num);

	showbits(num);
	printf("\n");
	
	printf("\n max of number " );
	max(a,b);
	printf("\n");
	
	clr_rt_st_bit(num);
	printf("\n");

	set_rt_clr_bit(num);
	printf("\n");

	clr_lt_st_bit(num);
	printf("\n");

        set_lt_clr_bit(num);
	printf("\n");

	showbits(set_s_d(num, a, b));
	printf("\n");

	showbits(clr_s_d(num, a, b));
        printf("\n");

	showbits(tog_s_d(num, a, b));
        printf("\n");

	return 0;
	
}

#endif

//12. Write a macro getbits (x,p,n) that retuns (left adjusted) n-bit field of x that begins at position p.

#if 0

#define getbits(x, n, p) ((x & ((~0 << (31-n)) >> 31-p)) >> p-n)

int main()
{
	int x;		//input number
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

//10. Write a function setbits (x,p,n,y) that returns x with the ‘n’ bits that begin at position p set to the right most n bits of y, leaving the other bits unchanged.

#if 0

int setbits(int x, int p, int n, int y);

int main()
{
	int x;		//input number
	int p;		//position number
	int y;		//reference number
	int n;		//number of bits

        printf("\nEnter the x: ");
        scanf("%d",&x);
        showbits(x);
        printf("\n");

        printf("\nEnter the position p: ");
        scanf("%d",&p);

        printf("\nEnter the y: ");
        scanf("%d",&y);
        showbits(y);
        printf("\n");
	
	printf("\nEnter the number of bits n: ");
        scanf("%d",&n);
	
	showbits(setbits(x, p, n, y));

	return 0;
}

int setbits(int x, int p, int n, int y)
{
	return ((y & (~(~0 << n))) << (p-n)) | ((~(get_r_bits(x, p, n))) & x);
}

#endif


