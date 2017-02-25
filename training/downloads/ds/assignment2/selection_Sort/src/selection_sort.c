#include "header.h" //include header file

void selection_sort(int a[MAX]) //selection sort function
{
	int i; //variable to traverse by loop
	int j; //variable to traverse by loop
	int t = 0; //temporary variable to swap elements
	int min = 0; //index number of the minimum number

	for ( i = 0; i < n; i++ ) { //traversing by loop

		for (j=i+1; j < n ; j++)  
			if ( a[min] > a[j] ) 
				min = j;
		
	//swapping the element
		t = a[min];
		a[min] = a[i];
		a[i] = t;
		min = i+1;
	}
}
