#include"header.h"

int main()
{
	char ch_option[LIMIT];
	int option;
	char ch_element[LIMIT];
	int element;
	
	printf("\n--------Stack Operation---------");
	printf("\n Enter option \n1. Push\t2. Pop\t3. Display\t4. Exit");
	printf("\nEnter the option : ");
	fgets(ch_option,MAX,stdin);
	rem_ent(ch_option);
	option = is_valid(ch_option);

	switch(option)
	{
	case 1:
		printf("\n1. Push");
		printf("\nEnter the element  : ");
		fgets(ch_element,MAX,stdin);
		rem_ent(ch_element);
		element = is_valid(ch_element);	
		
		push(element);
		main();
		break;
	case 2:
		printf("\n2. Pop");
		pop();
		main();
		break;
	case 3:
		printf("\n3. Display");
		
		display();
		main();
		break;
	case 4: 
		break;
	default :
		printf("\n Invalid Input");
	}

	return 0;
}

		

