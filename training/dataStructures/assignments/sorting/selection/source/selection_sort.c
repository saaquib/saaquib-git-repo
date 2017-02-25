#include"header.h"

void selection_sort(int *arr, int n)
{
	int i;
	int j;
	int min = 0;
	for ( i = 0; i < n; i++) 
	{
		min = i;
		for (j = i + 1; j < n; j++) 
		{
			if ( arr[j] < arr[min] ) 
				min = j;
		}
	swap(&arr[i], &arr[min]);
	}
}
