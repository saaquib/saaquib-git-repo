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

        printf("\n enter the string: ");
        fgets(s, n, stdin);
	
	printf("\n enter size to be copied: ");
        fgets(ch_p,MAX,stdin);
        p = is_valid(ch_p);

        str_n_cpy(d, s, p);

        printf("\nsource string:        %s", s);
        printf("\ndestination string:   %s", d);
        printf("\n");

        return 0;
}
