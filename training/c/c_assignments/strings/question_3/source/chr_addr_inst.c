#include"header.h"

char* chr_addr_inst(char *str, char chr)
{
	int i = 0;
        while(*(str + i) != chr)
		i++;
	
	return (str + i);
}
