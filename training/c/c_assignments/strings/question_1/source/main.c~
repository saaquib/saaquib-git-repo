#include"header.h"

int main()
{

        char ch_n[MAX];         // size of array in strings form
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

        str_cpy(d, s);

        printf("\nsource string:        %s", s);
        printf("\ndestination string:   %s", d);
        printf("\n");

        return 0;
}
