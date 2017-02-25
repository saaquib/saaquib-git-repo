#include "header.h" //include header file

void quick_sort(int a[10],int i,int j) //function for quick sort
{
	if ( i <  j ) {
	int pivot = i;
	int last = j;
	int t;
	while ( i <= j ) {
		while ( a[i] <= a[pivot] ) 
			i++;
		while ( a[j] > a[pivot] )
			j--;
		if ( i < j ) {
			t = a[j];
			a[j] = a[i];
			a[i] = t;
			i++;
			j--;
		}
		
	}
	
//	if ( j == pivot )
//	quick_sort(a,pivot+1,last);
//	else {
	t = a[pivot];
	a[pivot] = a[j];
	a[j] = t;
	quick_sort(a,pivot,j-1); //calling quick sort for first half
	quick_sort(a,j+1,last); //calling  quick sort for second half
	
//	}
}
}
	
