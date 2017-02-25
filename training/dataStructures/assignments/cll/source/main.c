#include"header.h"

int main()
{
	char ch_option[MAX];
	int option;
		
	head = NULL;
	temp = NULL;
	while(1)
	{
	printf("\nenter option: ");
	fgets(ch_option,MAX,stdin);
	rem_ent(ch_option);
	option = is_valid(ch_option);
	
		switch(option)
		{
			case 1:
				insert_at_begining();
				break;
	
			case 2:
				insert_at_end();
				break;
	
			case 3:
				delete();
				break;
			case 4:
			display();
				break;
				
			case 5:
				exit(1);
		}
	}
	return 0;
}
