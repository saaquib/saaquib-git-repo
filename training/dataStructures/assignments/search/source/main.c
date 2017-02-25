#include"header.h"

int main()
{
	char ch_option[MAX];
	int option;
	int pos;
	char ch_num[MAX];
	int num;
	
	head = NULL;
	traverse = NULL;
	printf("\t\t1. Insert at the beginning \n\
		2. search \n\
	       	3. Display \n\
	       11. Exit.");
	while(1)
	{
	printf("\nenter option: ");
	fgets(ch_option,MAX,stdin);
	rem_ent(ch_option);
	option = is_valid(ch_option);
	
	switch(option)
	{
		case 1:
			head = insert_at_begining();
			break;

		case 2:
			printf("\nenter number to be searched: ");
			fgets(ch_num,MAX,stdin);
			rem_ent(ch_num);
			num = is_valid(ch_num);
			printf("the number is at position : %d ",search(num));
			break;
		case 3:
			display();
			break;
			
		case 4:
			exit(1);
	}
	}
	return 0;
	
}
