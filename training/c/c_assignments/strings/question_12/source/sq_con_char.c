#include"header.h"

char* sq_con_char(char *str)
{
	int i;
	int j;
	int n;
	n = str_len(str);

	for(i = 0, j = 0; i < n; i++,j++)  {
		for(;(str[i] == str[i + 1]) && (str[i + 1] != '\0');i++);
		str[j] = str[i];
	}
	str[j] = '\0';
	return str;
}
