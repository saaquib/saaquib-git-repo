#include "header.h"


void merge_sort(int a[20],int first,int last)
{    
	int mid;
	if ( first < last ) {
		mid = ( first + last ) /2;
	//	printf("%d\n",mid);
		merge_sort(a,first,mid);
		merge_sort(a,mid+1,last);
		merge(a,first,mid,last);
	}
}

void merge(int a[20],int first,int mid,int last)
{

	int k = 0;
	int i = first;
	int j = mid + 1;
	
		while ( i<= mid && j <= last) {
		
		 if ( a[i] <= a[j] ) 
			b[k++] = a[i++];
		else if ( a[i] > a[j])
			b[k++] = a[j++]; 
		}
		
		while ( i <= mid )
			b[k++] = a[i++];
		while ( j <= last )
			b[k++] = a[j++];
			
		for ( i = first,j=0;i <= last;i++,j++ )
			a[i] = b[j];
}
