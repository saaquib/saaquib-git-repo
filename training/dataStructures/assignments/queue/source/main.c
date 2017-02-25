#include"header.h"

int main()
{
	char ch_option[LIMIT];
	int option;
	char ch_element[LIMIT];
	int element;
	printf("--------Queue Operation---------");
	while(1) {
		printf("\n Enter option \n1. Enque\t2. Deque\t3. Display\t4. Exit\n");
		printf("\nEnter the option : ");
		fgets(ch_option,MAX,stdin);
		rem_ent(ch_option);
		option = is_valid(ch_option);

		switch(option)
		{
			case 1:
				 printf("\n1. Enque");
				 printf("\nEnter the element  : ");
				 fgets(ch_element,MAX,stdin);
				 rem_ent(ch_element);
				 element = is_valid(ch_element);
				 enque(element);
				 break;
			case 2:
				 printf("\n2. deque");
				 deque();
			 	break;
			case 3:
				 printf("\n3. Display");
				 display();
				 break;
			case 4:
				 exit(0);
				 break;
			default :
				 printf("\nInvalid Input");
		}
	}
	return 0;
}
