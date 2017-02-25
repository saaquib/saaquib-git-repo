#include"header.h"
#include<string.h>
int str_spn(char *s1,char *s2)
{
	int i;
	int j;
	int count = 0;
	int l1 = str_len(s1);
	int l2 = str_len(s2);
	
	for(i = 0; i < l2; i++)  {
		if(count != i) return count;
		for(j = 0;j < l1; j++)  {
			if(*(s2 + i) == *(s1 + j)) {
				count++;
				break;
			}
		}
		
	}
	return count; 
}
