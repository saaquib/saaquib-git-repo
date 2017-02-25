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
	printf("\nascending order");
	asc_merge_sort(a, 0, n - 1);
	
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);

	printf("\ndescending order");
	des_merge_sort(a, 0, n - 1);
	
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);
	return 0;
}

