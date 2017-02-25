#include"header.h"

int main()
{
	union u u1;
	u1.a = 0x4142;
	if(u1.ch == 'B')
		printf("\nLittle Endian");
	else
		printf("\nBig Endian");
	return 0;
}
