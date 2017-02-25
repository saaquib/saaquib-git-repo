#include"header.h"

char* snappend(char *src, char *dest, int size)
{
	int dest_len = str_len(dest);
	int src_len = str_len(src); 
	int i = dest_len;
	int j = 0;


	for(i = dest_len, j = 0; i < (size + dest_len); i++, j++)
		*(dest + i) = *(src + j);
	*(dest + dest_len + size) = '\0';	

	return dest;
	
}
