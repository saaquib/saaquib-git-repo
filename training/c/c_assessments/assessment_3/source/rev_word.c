#include"header.h"

char* rev_word(char *str1)  
{
	char *temp_str;
	int len;
	int i, k;
	int count = 0;
	
	len = str_len(str1);
	printf("\n len %d",len);

	temp_str = (char *)malloc(len*sizeof(char));
	is_mem_valid(temp_str);

	for(i = len-1; i >= 0; i--)  {
		if(*(str1 + i) != ' '); 
		else  {
			k = i + 1; 
			static int j = 0;
			for(; (*(str1 + k) != ' ') && (*(str1 + k) != '\0');k++,j++,count++)
				*(temp_str + j) = *(str1 + k); 
			*(temp_str + j ) = ' ';
			j++;
			count++;
		}
	}
	for(i = 0; *(str1 + i) != ' '; i++,count++)
			*(temp_str + count) = *(str1 + i);
	*(temp_str + count) = '\0';
	return temp_str;
}

