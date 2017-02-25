#include<stdio.h>

void showbits(int c);		// To convert given number int0 binary

// 1. To check the number is power of two

#if 0

void is_power_of_2(int num);

int main()
{
	int num;		// input number
	
	printf("\nEnter the number to be checked if power of two or not: ");
	scanf("%d", &num);

	is_power_of_2(num);

	return 0;
}

void is_power_of_2(int num)
{
	int i;			// for looping
	int count = 0;		// for count
	
	for(i = 0; i <= 31; i++)  
		(num & (1 << i)) ? count++ : count;
	
	(count == 1) ? printf("\n %d is power of 2 ", num) : printf("\n %d is not power of 2 ", num);
	
	printf("\n");
}



#endif

// 2. To count the number of one's in a given number

#if 1

int count_1s(int num);

int main()
{
        int num;                // input number
        int i = 0;              // for looping
        int count = 0;          // for count

        printf("\nEnter the number: ");
        scanf("%d", &num);
	showbits(num);

	printf("\nThe number of one is : %d ", count_1s(num));
	printf("\n");

	return 0;
}

int count_1s(int num)
{
	int i = 0;              // for looping
        int count = 0;          // for count

	for(i = 0; i <= 31; i++)
                (num & (1 << i)) ? count++ : count;

        return count;
}

#endif

// 3. To multiply a given number by four using bitwise operator

#if 0

int mul_by_4(int num);

int main()
{
	int num;		// The number to be multiplied
	
	printf("\nEnter the number to be multiplied by 4: ");
        scanf("%d", &num);

	printf("\n 4 * %d = %d", num, mul_by_4(num));
	printf("\n");
	
	return 0;
}

int mul_by_4(int num)
{
	return (num << 2);
}

#endif

void showbits(int c)
{
        int i;
        int count = 0;
        for(i = sizeof(int)*8; i > 0; i--)  {
                printf("%d",( 1 & ( c >> (i-1) ) ) );
                count++;

                if(count % 8 == 0)
                        printf(" ");
	}
}
