#include"header.h"

int main()
{
	int a[MAX];
	int n;
	int i;
	printf("\nInsertion Sort");
	printf("\n Enter no:of elements");
	scanf("%d",&n);

	printf("\nEnter array elements");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("\ndescending");
	des_insertion_sort(a, n);
	
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);

	printf("\nascending");
	asc_insertion_sort(a, n);
	
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);

	return 0;
}

