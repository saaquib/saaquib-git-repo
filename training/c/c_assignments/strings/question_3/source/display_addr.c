#include"header.h"
void display_addr(char *s)
{
	int i = 0;
	while(*(s + i)) {
                printf("\n address of %c is %p",*(s + i), (s + i));
                i++;
        }
}
