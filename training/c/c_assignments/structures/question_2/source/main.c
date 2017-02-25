#include"header.h"

int main()
{	
	char num[MAX];
	union sample s1;
	
	printf("\n enter e value:");
	fgets(num,MAX,stdin);
	rem_ent(num);
	
	s1.e = is_valid(num);
	
	printf("\n a : %d",s1.a);
	printf("\n b : %d",s1.b); 
	printf("\n c : %d",s1.c); 
	printf("\n d : %d",s1.d); 
	printf("\n e : %d",s1.e); 

	return 0;
}
