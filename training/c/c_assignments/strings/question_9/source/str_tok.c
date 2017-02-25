#include"header.h"
char* str_tok(char *str, char delim)
{
	int i = 0;
	while(*(str + i) != delim)  i++;

			*(str + i) = '\n';
//	str = str + i + 1;
	return str;
}
