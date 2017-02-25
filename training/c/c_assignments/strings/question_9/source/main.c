#include"header.h"

int main()
{

    char ch_n[MAX];         // size of array in strings form
    char ch_p[MAX];
	char delim;
	int p;
	int n;                  // size of array 
	char *s;                // source string


    printf("\n enter size of array: ");
    fgets(ch_n,MAX,stdin);
    n = is_valid(ch_n);

    s = (char *)malloc(n*sizeof(char));
    is_mem_valid(s);

    printf("\n enter the string: ");
    fgets(s, n, stdin);
	rem_ent(s);
	
	printf("\n enter the delimiter: ");
	delim = fgetc(stdin);

	s = str_tok(s,delim);                                                       
    printf("\n%s",s);                                 
	
	return 0;
}
