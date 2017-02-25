#include"header.h"

int main()
{
        
        char ch_n[MAX];         // size of array in strings form
        int n;                  // size of array 
        char ch_s[MAX];
        char *s;                // source string
        char ch_c;
        char *add_of_chr;               // destination string
	int i = 0;

        printf("\n enter size of array: ");
        fgets(ch_n,MAX,stdin);
        n = is_valid(ch_n);
        
        s = (char *)malloc(n*sizeof(char));
        is_mem_valid(s);

        printf("\n enter the string: ");
        fgets(s, n, stdin);
        
	display_addr(s);
	
        printf("\n enter the char whose address is to returned : ");
        ch_c = fgetc(stdin);

        add_of_chr = chr_addr_inst(s, ch_c);

        printf("\naddress of %c is :    %p", ch_c,add_of_chr);
        printf("\n");
        
        return 0;
}
