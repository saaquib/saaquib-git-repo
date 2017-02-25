#include"header.h"

int main()
{

        char ch_s1[MAX];         // size of array in strings form
        char ch_s2[MAX];
        char *s1;                // source string
        char *s2;                // destination string
	int i_s1;
	int i_s2;
        int result;

        printf("\n enter size of first string: ");
        fgets(ch_s1,MAX,stdin);
        i_s1 = is_valid(ch_s1);

        s1 = (char *)malloc(i_s1*sizeof(char));
        is_mem_valid(s1);

	printf("\n enter size of second string: ");
        fgets(ch_s2,MAX,stdin);
        i_s2 = is_valid(ch_s2);

        s2 = (char*)malloc(i_s2*sizeof(char));
        is_mem_valid(s2);

        printf("\n enter the first string: ");
        fgets(s1, i_s1, stdin);
		rem_ent(s1);
		
        printf("\n enter the seacond string: ");
        fgets(s2, i_s2, stdin);
		rem_ent(s2);
		
	result = str_spn(s1, s2);

	printf("\n%d", result);

	printf("\n");

	return 0;

}
