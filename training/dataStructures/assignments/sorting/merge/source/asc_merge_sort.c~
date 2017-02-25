#include"header.h"

void asc_merge_sort(int *arr, int low, int high)
{
	int mid;
	if(low < high)
	{
		mid = (low + high) / 2;
		asc_merge_sort(arr, low, mid );
		asc_merge_sort(arr, mid + 1, high);
		asc_merge(arr, low, mid, high);
	}
	else
		return;
}
	

