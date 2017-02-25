#include"header.h"

int main()
{
	char ch_option[MAX];
	int option;
	char ch_pos[MAX];
	int pos;
	char ch_num[MAX];
	int num;
	
	head = NULL;
	temp = NULL;
	printf("\t\t1. Insert at the beginning \n\
		2. Insert at the end \n\
		3. Insert at a given position \n\
		4. Insert before a given position \n\
		5. Insert after a given position \n\
		6. Insert before a given number \n\
		7. Insert after a given number \n\
		8. Insert at the middle \n\
		9. Insert at penultinate node \n\
	       10. Display \n\
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
			insert_at_begining();
			break;

		case 2:
			insert_at_end();
			break;

		case 3:
			printf("\nenter position: ");
			fgets(ch_pos,MAX,stdin);
			rem_ent(ch_pos);
			pos = is_valid(ch_pos);
			
			insert_at_given_position(pos);
			break;

		case 4:
			printf("\nenter position: ");
			fgets(ch_pos,MAX,stdin);
			rem_ent(ch_pos);
			pos = is_valid(ch_pos);

			insert_before_given_pos(pos);
			break;

		case 5:
			printf("\nenter position: ");
			fgets(ch_pos,MAX,stdin);
			rem_ent(ch_pos);
			pos = is_valid(ch_pos);

			insert_after_given_pos(pos);
			break;

		case 6:
			printf("\nenter num: ");
			fgets(ch_num,MAX,stdin);
			rem_ent(ch_num);
			num = is_valid(ch_num);

			insert_before_given_num(num);
			break;

		case 7:
			printf("\nenter num: ");
			fgets(ch_num,MAX,stdin);
			rem_ent(ch_num);
			num = is_valid(ch_num);

			insert_after_given_num(num);
			break;

		case 8:
			insert_at_middle();
			break;

		case 9:
			insert_at_penultinate();
			break;
		
		case 10:
			delete_at_begining();
			break;

		case 11:
			delete_at_end();
			break;

		case 12:
			printf("\nenter position: ");
			fgets(ch_pos,MAX,stdin);
			rem_ent(ch_pos);
			pos = is_valid(ch_pos);
			
			delete_at_given_position(pos);
			break;
		case 13:
			printf("\nenter position: ");
			fgets(ch_pos,MAX,stdin);
			rem_ent(ch_pos);
			pos = is_valid(ch_pos);
			
			delete_after_given_position(pos);
			break;
		case 14:
			printf("\nenter num: ");
			fgets(ch_num,MAX,stdin);
			rem_ent(ch_num);
			num = is_valid(ch_num);
			
			delete_given_num(num);
			break;
		case 15:
			printf("\nenter num: ");
			fgets(ch_num,MAX,stdin);
			rem_ent(ch_num);
			num = is_valid(ch_num);
			
			delete_after_given_num(num);
			break;
		case 19:
			display();
			break;
			
		case 20:
			exit(1);
	}
	}
	return 0;
	
}


	
	
	

