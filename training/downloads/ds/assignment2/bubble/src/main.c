#include "header.h" //include header

int main() //main function
{
	
	int a[20]; //integer array to hold input
	char *str = NULL; //character string to get input
	int i = 0; //variable for loop
	
	// dynamic memory allocation of string

	if ( NULL == (str = (char *)malloc(sizeof(char)*MAX))) {
		printf ("malloc failed\n");
		exit(0);
	}
	
	//getting input of number of elements from the user
	
	printf ("enter the number of elements\n");
	if ( NULL == (fgets (str,MAX,stdin))) {
		printf ("enter input\n");
		exit(0);
	}
	n = atoi(str); //converting from string to integer

	printf ("enter the elements\n");

	//getting elements from user
	for( i = 0;i < n; i++ ) {
		if ( NULL == (fgets(str,MAX,stdin))) {
			printf("enter input\n");
			exit(0);
		}
		a[i] = atoi(str); //converting the input from string to integer
	}

	bubblesort(a); //calling bubble sort function
	printf("the elements after sorting are\n");

	//printing the result after sorting
	for( i = 0; i < n; i++ ) 
		printf("%d\t",a[i] );

}
