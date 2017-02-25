#include"header.h"

int str_cmp(char *str1, char *str2)
{
	int sr1_len = str_len(str1);
	int sr2_len = str_len(str2);
	int i;
	int n =  sr2_len;
	int count = 0;
	for(i = 0;((n > 0) && (str1[i] != '\0') && (str2[i] != '\0') && (i < (sr1_len + sr2_len))); i++,n--) {
		if(((((*(str1 + i) - *(str2 + i)) == 0) || (*(str1 + i) - *(str2 + i)) == 32) || (*(str1 + i) - *(str2 + i)) == -32));
		else count++;
	}
		
	if(count == 0) 
		return 0;
	else 	
		return 1;
			
}
