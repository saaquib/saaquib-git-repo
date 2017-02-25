#include"header.h"

int main()
{

        char ch_n[MAX];         // size of array in strings form
        char ch_a[MAX];
        char *s1;                // source string
        char *s2;                // destination string
	int n;
        signed int result;

        printf("\n enter size of array: ");
        fgets(ch_n,MAX,stdin);
        n = is_valid(ch_n);

        s1 = (char *)malloc(n*sizeof(char));
        is_mem_valid(s1);

        s2 = (char*)malloc(n*sizeof(char));
        is_mem_valid(s2);

        printf("\n enter the first string: ");
        fgets(s1, n, stdin);

        rem_ent(s1);

        printf("\n enter the seacond string: ");
        fgets(s2, n, stdin);

        rem_ent(s2);

        result = str_case_cmp(s1, s2);

        printf("\n%d", result);

	printf("\n");

        return 0;
}
