#include"header.h"

void rev_str(char *str)
{
	int i = 0;
	int flag = 0; 
	int length;
	char temp;
	length = str_len(str);      
	for(i=0; i< (length / 2 ); i++) {
		temp = str[i];
		str[i] =str[length - i - 2];
		str[length - i - 2]= temp;
	}
}
