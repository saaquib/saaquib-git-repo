#include<stdio.h>
void calculator(int, int, int *, int *, float *, int * );

int main()
{
	int n1 = 6;
	int n2 = 3;
	int add;
	int sub;
	float div;
	int mod;
	calculator(n1, n2, &add, &sub, &div, &mod);
	printf("%d   %d  %f  %d", add,sub,div,mod);

	return 0;
}

void calculator(int n1, int n2, int *add, int *sub, float *div, int *mod)
{
	*add = n1 + n2;
	*sub = n1 - n2;
	*div = n1 / n2;
	*mod = n1 % n2;
}

