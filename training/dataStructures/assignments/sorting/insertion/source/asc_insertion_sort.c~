#include"header.h"

void asc_insertion_sort(int *arr, int n)
{
	int i;
	int j;
	int k;
	for ( i = 0, j = 1; i < (n - 1); i++, j++) 
	{
		for (k = 0; k <= i; k++) 
		{
			if ( arr[i - k] > arr[j - k] ) 
			swap(&arr[i - k], &arr[j - k]);	
		}
	}
}
