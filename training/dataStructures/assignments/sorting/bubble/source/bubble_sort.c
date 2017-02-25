#include"header.h"

void asc_bubble_sort(int *arr, int n)
{
	int i;
	int j;
	int m = n;
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < (n-1); j++)
		{
			if( arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}
