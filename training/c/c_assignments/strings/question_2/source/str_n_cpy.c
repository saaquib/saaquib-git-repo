#include"header.h"

void str_n_cpy(char *dbuf, char *sbuf, int size)
{
        while(size--)
		(*(dbuf++) = *(sbuf++));
	*dbuf = '\0';
}
