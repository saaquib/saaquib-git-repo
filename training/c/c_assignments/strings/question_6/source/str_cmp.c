#include"header.h"

signed int str_cmp(char *str1, char *str2)
{
	int sr1_len = str_len(str1);
	int sr2_len = str_len(str2);
	int i;
	int gre = 0;
	int less = 0;
	for(i = 0;((str1[i] != '\0') && (str2[i] != '\0') && (i < (sr1_len + sr2_len))); i++) {
		if((str1[i] - str2[i]) == 0);
		else if((str1[i] - str2[i]) > 0) {
			gre++;
			break;
		}
		else {
			less++;
			break;
		}
	}
	if(gre != 0)
		return 1;

	if(less != 0)
		return (-1);

	return 0;
			
}
