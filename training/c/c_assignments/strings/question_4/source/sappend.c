#include"header.h"

char* sappend(char *src, char *dest)
{
	int dest_len = str_len(dest);
	int src_len = str_len(src); 
	int i;
	int j;

	for(i = dest_len, j = 0; i <= (src_len + dest_len); i++, j++)
		dest[i] = src[j];

	return dest;
}
