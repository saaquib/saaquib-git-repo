#include"header.h"
int main()
{
	char ch_size[MAX];         // size of array in strings form
	char *str1;               // first string
	char *str2;               // second string
	int size;
	
    printf("\n enter size of array: ");
    fgets(ch_size,MAX,stdin);
    size = is_valid(ch_size);

	str1 = (char *)malloc(size*sizeof(char));
    is_mem_valid(str1);

	str2 = (char *)malloc(size*sizeof(char));                                   	is_mem_valid(str2);
	
	printf("\n enter the string: ");
    fgets(str1, size, stdin);
    rem_ent(str1);
//	scanf("%s",str1);

	str2 = rev_word(str1);

	printf("\n%s ",str2);

	return 0;
}
