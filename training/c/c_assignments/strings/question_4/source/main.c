#include"header.h"

int main()
{

        char ch_n[MAX];         // size of array in strings form
        char ch_p[MAX];
	int p;
	int n;                  // size of array 
	char *s;                // source string
        char *d;                // destination string

        printf("\n enter size of array: ");
        fgets(ch_n,MAX,stdin);
        n = is_valid(ch_n);

        s = (char *)malloc(n*sizeof(char));
        is_mem_valid(s);

        d = (char*)malloc(n*sizeof(char));
        is_mem_valid(d);

        printf("\n enter the source string: ");
        fgets(s, n, stdin);

	rem_ent(s);

	printf("\n enter the destination string: ");
        fgets(d, n, stdin);

	rem_ent(d);

	realloc(d, 2*n);

	d = sappend(s, d);

	printf("\n%s",d);

	return 0;
}
