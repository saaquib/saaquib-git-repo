#include<stdio.h>
#include<string.h>
#define MAX 32
extern int str_len(char *);

extern int is_valid(char s[]);

extern void is_mem_valid(char *);

char* chr_addr_inst(char *, char);

void display_addr(char *);
int main()
{
	
	char ch_n[MAX];		// size of array in strings form
	int n;			// size of array 
	char ch_s[MAX];
	char *s;		// source string
	char ch_c;
	char *add_of_chr;		// destination string

	printf("\n enter size of array: ");
	fgets(ch_n,MAX,stdin);
	n = is_valid(ch_n);
	
	s = (char *)malloc(n*sizeof(char));
	is_mem_valid(s);
	
	
	printf("\n enter the string: ");
	fgets(s, n, stdin);
	
//	display_addr(s);
	while(*s != '\0')  {
                printf("\n%p",s);
		s++;
}

	printf("\n enter the char whose address is to returned : ");
        ch_c = fgetc(stdin);

	add_of_chr = chr_addr_inst(s, ch_c);

	printf("\naddress of %c is :	%p", ch_c,add_of_chr);
	printf("\n");

	return 0;
}

char* chr_addr_inst(char *str, char chr)
{
	if(*(str++) == chr)
		return str;
}

void display_addr(char *str)
{
	while(*(str++) != '\0')  {
		printf("\n%p",str);
	}
}


