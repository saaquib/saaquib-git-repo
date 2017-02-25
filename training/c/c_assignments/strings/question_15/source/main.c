#include"header.h"

int main()
{

        char ch_n[MAX];         // size of array in strings form
        char ch_p[MAX];
	char ch;
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

	printf("\n enter position where to be inserted: ");
	fgets(ch_p, MAX, stdin); 
	p = is_valid(ch_p);
	
	printf("\n enter character to be inserted: ");
	ch = fgetc(stdin);
	
	s = insert_char(s, ch, p);

	printf("\nresulted string:   %s", s);
        printf("\n");

        return 0;
}
