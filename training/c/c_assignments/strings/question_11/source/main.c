#include"header.h"

int main()
{	char ch_s1[MAX];         // size of array in strings form
        char *s1;                // source string
        int i_s1;
	
        printf("\n enter size of string: ");
        fgets(ch_s1,MAX,stdin);
        i_s1 = is_valid(ch_s1);

        s1 = (char *)malloc(i_s1*sizeof(char));
        is_mem_valid(s1);

        printf("\n enter the string: ");
        fgets(s1, i_s1, stdin);

        rem_ent(s1);

	rev_str(s1);

	printf("\n%s", s1);
	printf("\n");

	return 0;

}
