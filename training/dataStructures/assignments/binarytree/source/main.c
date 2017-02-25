#include"header.h"

NODE *root = NULL;
NODE *traverse = NULL;

#define ONE 1

int main()
{
	char ch_num[MAX];
	int num;
	char ch_option[MAX];
	int option;

	while(ONE)
	{
		printf("\n\t\t1. Insert at the beginning \n\
		2. pre order \n\
		3. post order \n\
		4. in order \n\
		5. delete \n");
		printf("\nenter option: ");
		fgets(ch_option,MAX,stdin);
		rem_ent(ch_option);
		option = is_valid(ch_option);
	
		switch(option)
		{
			case 1:
				printf("\nInsert node");	
				NODE *new = MEM_CREATE;
				IS_MEM_ALLOC(new);		
				new = create();
				insert(new);
				break;

			case 2:
				printf("\n pre order\t");
				if (root == NULL )
					printf("\n tree is empty");
				pre_order(root);
				break;
			case 3:
				printf("\n post order\t");
				if (root == NULL )
					printf("\n tree is empty");
				post_order(root);
				break;
			case 4:
				printf("\n in order\t");
				if (root == NULL )
					printf("\n tree is empty");
				in_order(root);
				break;
			case 5:
				printf("\nenter num: ");
				fgets(ch_num,MAX,stdin);
				rem_ent(ch_num);
				num = is_valid(ch_num);	
				delete(num);
				break;
			case 6:
				exit(0);
				break;
		}
	}
	return 0;
}
	

