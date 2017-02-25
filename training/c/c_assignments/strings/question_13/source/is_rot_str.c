#include"header.h"

int is_rot_str(char *str1, char *str2)
{
	int i = 0;
	int j = 0;
	int l1 = str_len(str1);
	int l2 = str_len(str2);
	char *t;
	t = (char*)malloc(2*l1);
	
	str_cpy(t,str1);

	t = sappend(t,str1);
	
	while((*(str2 + i) != '\0') && (*(t + j) != '\0'))  {                        
		if(*(str2 + i) == *(t + j)) {
			j++;                                                                
			i++;                                                                
		}                                                                       
		else j++;                                                               
	}

	return i;
}
