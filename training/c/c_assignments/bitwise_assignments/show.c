#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void showbits(int c)
{       
        int i;
        int count = 0;
        for(i = sizeof(int) * 8; i > 0; i--)
        {
                printf("%d",(1 & ( c >> ( i - 1 ) ) ) );
                count++;
                if(count%8==0)
                        printf(" ");
                
        }
}

int getsbit(int num,int s)   // get the sth bit from num
{
        int res;
        res = (1<<(s-1)) & num;
        return res;
}


int getbits(int x, int n, int p)    // get n number of bits from position p of x
{
	return ((x & ((~0 << (31-n)) >> 31-p)) >> p-n);
}

int get_r_bits(int x, int p, int n)  // get n number of bits set from position p of x
{

	return ((~( ~0 << p )) & ( ~0 << p -n ));

}

int shift(int n, int s, int d)  // shift s bit to position d
{
      return ((((1 << s-1) & n) >> s-1) << d-1);
}

int is_valid(char s[])
{
	int i;
	int n = 0;

	for(i =0; i < strlen(s); i++)  {
		if(((s[i] >= '0') && (s[i] <= '9')) || (s[i] == '-') || (s[i] == ' ')) {
			if((s[i] != '-') && (s[i] != ' ' ))
				n = n * 10 + (s[i] - '0');
		}
		else  {
			printf("\n Invalid input ");
			exit(0);
		}
	}
	if(s[0] == '-')
		return ((~n) + 1);
	else
		return n;

	if(s[i] == ' ')
		;
	else return n;
}
