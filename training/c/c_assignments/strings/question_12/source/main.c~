#include"header.h"

int main()
{

        char ch_n[MAX];         // size of array in strings form
        int n;                  // size of array 
        char *s;                // source string
        
        printf("\n enter size of array: ");
        fgets(ch_n,MAX,stdin);
        n = is_valid(ch_n);

        s = (char *)malloc(n*sizeof(char));
        is_mem_valid(s);

        printf("\n enter the string: ");
        fgets(s, n, stdin);

	s = sq_con_char(s);

	printf("\nafter squeezing : %s",s);

	printf("\n");
	
	return 0;

}
