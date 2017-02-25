#include "header.h"

int binary_search(int a[20],int key)
{
	int i;
	int j;
	int mid;
	int last = n;
	int first = 0;
	int t;
	
	for ( i = 0; i < n; i++ ) {
		for ( j = i+1; j < n; j++ ) {
			if ( a[i] < a[j] ) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}	
	}
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	while ( first != last ) {

		mid = (first +last )/2;
		if ( a[mid] == key )
			return 1;
		else if ( a[mid] > key )
			mid = first;
		else
			mid = last;
	}
	return 0;
}		
