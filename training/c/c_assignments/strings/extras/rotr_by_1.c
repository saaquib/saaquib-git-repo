#include"header.h"

char* rotr_by_1(char *str)
{
	int i;
	int len;
	len = str_len(str);
	for(i = len - 1; i >= 0; i--)
		*(str + i + 1) = *(str + i);

	*str = *(str + len);
	*(str + len) = '\0';
	return str;
}
