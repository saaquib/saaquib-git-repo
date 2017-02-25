#include"header.h"
void display_addr(char *s)
{
	int i = 0;
	while(*(s + i)) {
                printf("\n %p", (s + i));
                i++;
        }
}
