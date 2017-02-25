#include<stdio.h>

// 1. To check max of two number using bitwise operator

#if 0
int max(int a, int b);

int main()
{
	int a;	//first number
	int b;	//second number
	
	printf("\nEnter first number: ");
	scanf("%d", &a);

	printf("\nEnter second number: ");
        scanf("%d", &b);

	max(a,b);

	printf("\n");
	
	return 0;
	
}

int max(int a, int b)
{
	int i;                                                  
        int count = 31;                                           
        for(i = 31; i >= 0; i--){                                   
                if((a ^ b) & (1 << i)){                         
                        if(a & (1 << count)){                     
                                printf("\n%d is big",a);                 
                                break; 
			}
                        else {
				printf("\n%d is big",b);                   
			 	break;
			}
                }
                else count--; 
	}
}
#endif

// 2. To print sum of array elements

#if 0
int main()
{
	int a[100];
	int sum = 0;
	int i, j, n;

	printf("\n enter number of elements:");
        scanf("%d", &n);

	printf("\n enter elements of array: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(j = 0; j < n; j++)
		sum = sum + a[j];

	printf("\nsum of array is : %d", sum);
	printf("\n");

	return 0;
}
#endif

// 3. To print fibonacci series of n numbers

#if 0

int main()
{
	int n, i;
	int a[100];
	a[0] = 0;
	a[1] = 1;

	printf("\n enter n value:");
	scanf("%d", &n);

        a[0] = 0;
        a[1] = 1;
	
	for(i = 0;i < (n-2); i++) {
		a[i + 2] = a[i +1] + a[i];
	}
	
	printf("\n fibonacci series: ");

	for(i = 0; i < n; i++) {
		printf("%d  ", a[i]);
	}
	
	printf("\n");

	return 0;
}
#endif

#if 1
int main()
{
        int a[10][10];
	int b[10][10];
        int i, j, n, m;

	printf("\n enter n value:");
        scanf("%d", &n);

	printf("\n enter m value:");
        scanf("%d", &m);

	printf("\n enter %d elements of array a", n*m);
	printf("\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++) 
			scanf("%d", &a[i][j]);
	}

	printf("\n array a: ");
	printf("\n");
        for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++)
                        printf("%d    ", a[i][j]);
        printf("\n");
        }

	printf("\n enter %d elements of array b", n*m);
        printf("\n");
        for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++)
                        scanf("%d", &b[i][j]);
        }
	
	printf("\n array b: ");
	printf("\n");
	for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++)
                        printf("%d    ", b[i][j]);
	printf("\n");
        }


	printf("\n sum of arrays: ");
	printf("\n");
        for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++)
                        printf("%d    ", (a[i][j] + b[i][j]));
        printf("\n");
        }
	
	return 0;
}
#endif

