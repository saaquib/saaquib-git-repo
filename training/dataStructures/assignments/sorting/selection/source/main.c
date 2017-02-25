#include"header.h"

int main()
{
	int a[MAX];
	int n;
	int i;
	printf("\nSelection Sort");
	printf("\n Enter no:of elements");
	scanf("%d",&n);

	printf("\nEnter array elements");
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	printf("\n descending");
	des_selection_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);

	printf("\n ascending");
	selection_sort(a, n);
	for(i = 0; i < n; i++)
		printf("%d ",a[i]);

	return 0;
}

