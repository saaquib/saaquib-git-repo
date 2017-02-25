#include"header.h"

int main()
{

    char ch_n1[MAX];         // size of array in strings form
	char ch_n2[MAX];
    char ch_a[MAX];
    char *s1;                // source string
    char *s2;                // destination string
	int n1;
	int n2;
    signed int result;

    printf("\n enter size of first array: ");
    fgets(ch_n1,MAX,stdin);
    n1 = is_valid(ch_n1);

    s1 = (char *)malloc(n1*sizeof(char));
    is_mem_valid(s1);

	printf("\n enter size of second array: ");
    fgets(ch_n2,MAX,stdin);
    n2 = is_valid(ch_n2);

    s2 = (char*)malloc(n2*sizeof(char));
    is_mem_valid(s2);

    printf("\n enter the first string: ");
    fgets(s1, n1, stdin);
	rem_ent(s1);

    printf("\n enter the second string: ");
    fgets(s2, n2, stdin);

    rem_ent(s2);

	s1 = rem_sub_str(s1, s2);

	printf("\nthe resuled string : %s", s1);

	printf("\n");

	return 0;

}
