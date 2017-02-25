#include "header.h" //include header

int *bubblesort(int a[10]) //bubble sort function definition
{
	int i; //variable for loop
	int j; //variable for loop
	int t; //temporary variable for swapping

	for ( i = 0; i < n; i++ ) { //traverse the loop
		for ( j = 0; j < n ; j++ ) {
			if ( a[j] > a[j+1] ) { //swapping the elements
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	return 0;
}
		
