#include"header.h"

void asc_merge(int *arr, int low, int mid, int high)
{
	int left[MAX];
	int right[MAX];
	int buffer[MAX];
	int i;
	int j;
	int k = 0;
	int l1 = low;
	int l2 = mid + 1;
	
	while((l1 <= mid) && (l2 <= high))
	{
			if(arr[l1] < arr[l2])
			{	
				buffer[k++] = arr[l1++];
			}
			else
			{
				buffer[k++] = arr[l2++];
			}
	}

	while (l1 <= mid) {
			buffer[k++] = arr[l1++];
	}

	while (l2 <= high) {
			buffer[k++] = arr[l2++];
	}

	for(i = low, j = 0; i <= high; i++, j++)
		arr[i] = buffer[j];
}
			

