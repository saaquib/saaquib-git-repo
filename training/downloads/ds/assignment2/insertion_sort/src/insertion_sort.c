#include "header.h" //include header

void insertion_sort(int a[MAX]) //insertion sort function definition
{
	int i; //variable for loop
	int j; //variable for loop
	int temp; //tempoarary variable to hold value
	
	for ( i = 1; i < n; i++ ) { //loop to traverse
			temp = a[i];
		for ( j = i-1; j >= 0; j-- ) {
			if ( temp < a[j] ) {
				a[j+1] = a[j];
				a[j] = temp;
			}
		
		}
	}
}
	
