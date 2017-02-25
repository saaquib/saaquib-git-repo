#include"header.h"

void des_selection_sort(int *arr, int n)
{
	int i;
	int j;
	int max = 0;
	for ( i = 0; i < n; i++) 
	{
		max = i;
		for (j = i + 1; j < n; j++) 
		{
			if ( arr[j] > arr[max] ) 
				max = j;
		}
	swap(&arr[i], &arr[max]);
	}
}
