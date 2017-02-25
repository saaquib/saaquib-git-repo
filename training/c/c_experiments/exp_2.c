#include<stdio.h>

#if 0 

int main()
{
	int var;
	unsigned int *ptr_var;
	unsigned int **ptr_ptr_var;

	printf("\n Enter var value: ");
	scanf("%d", &var);

	ptr_var = &var;
	ptr_ptr_var = &ptr_var;

	printf("\n Var is: %d ", var);

	printf("\n ptr_var is : %p ", ptr_var);

	printf("\n var at ptr_var: %d ",*ptr_var) ;

	printf("\n address of ptr_var: %p ",ptr_ptr_var) ;
	
	printf("\n address of ptr_ptr_var: %p ",&ptr_ptr_var) ;
	
	printf("\n value at ptr_ptr_var: %p ",*ptr_ptr_var) ;

	return 0;

}

#endif 

#if 0
void swap(int *a, int *b);

int main()
{
	int var1;
	int var2;

	printf("\n Enter var1 value: ");
        scanf("%d", &var1);

	printf("\n Enter var2 value: ");
        scanf("%d", &var2);

	printf("\n before swap");
	
	printf("\nvar1 =  %d    var2 = %d",var1,var2);

	swap(&var1, &var2);

	printf("\n after swap");

        printf("\nvar1 =  %d    var2 = %d",var1,var2);

	return 0;
}

void swap(int *a, int *b)
{
	int temp = 0 ;

	temp = *b;
	*b = *a;
	*a = temp;

}

#endif

#if 0

#define PI 3.14

void area_peri_of_circle(int , float *, float *);

int main()
{
	int rad;
	float area;
	float perimeter;

	printf("Enter radius: ");
	scanf("%d",&rad);
	
	area_peri_of_circle(rad, &area, &perimeter);
	
	printf("\n area = %f",area);
	printf("\n peri = %f",perimeter);

	return 0;
}

void area_peri_of_circle(int rad, float *a, float *p)
{
	*a = PI * rad * rad;
	*p = 2 * PI * rad;
}
#endif

#if 1

void add_sub_mul(int, int, int *, int *, int *);

int main()
{
	int var1;
        int var2;
	int add;
	int sub;
	int mul;

        printf("\n Enter var1 value: ");
        scanf("%d", &var1);

        printf("\n Enter var2 value: ");
        scanf("%d", &var2);

	add_sub_mul(var1, var2, &add, &sub, &mul);

	printf("\n sum = %d",add);
        printf("\n sub = %d",sub);
	printf("\n mul = %d",mul);
	printf("\n");

        return 0;

}

void add_sub_mul(int v1, int v2, int *fa, int *fs, int *fm)
{
	*fa = v1 + v2;
	*fs = v1 - v2;
	*fm = v1 * v2;
}
#endif


