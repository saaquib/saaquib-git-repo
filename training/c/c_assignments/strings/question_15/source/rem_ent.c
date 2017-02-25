#include"header.h"
void rem_ent(char *str)
{
	int slen = str_len(str);
	*(str + slen) = '\0';
}
