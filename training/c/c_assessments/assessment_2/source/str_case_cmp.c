#include"header.h"

signed int str_case_cmp(char *str1, char *str2)
{
        int sr1_len = str_len(str1);
        int sr2_len = str_len(str2);
        int i;
		
        for(i = 0;(( *(str1 + i) != '\0') && ( *(str2 + i) != '\0') && (i < (sr1_len + sr2_len))); i++) {
                if(((((*(str1 + i) - *(str2 + i)) == 0) || (*(str1 + i) - *(str2 + i)) == 32) || (*(str1 + i) - *(str2 + i)) == -32));
                else if(((*(str1 + i) - *(str2 + i)) > 0) || ((*(str1 + i) - *(str2 +i) + 32 ) > 0 )){
                        return 1;
                }
                else {
                        return -1;
		}
        
	}
        return 0;
        
}

