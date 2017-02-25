#include"header.h"
#include<string.h>
int main()
{
	struct frame1 f1;
	struct frame2 f2;
	struct frame2 f4;
	struct frame3 f3;
	printf("%d\n", sizeof(f1));
	printf("%d\n", sizeof(f2));
	printf("%d\n", sizeof(f3));
	strcpy(f4.data, "saaquib");
	printf("%s\n", f4.data);
	printf("%d\n", sizeof(f4));
	return 0;
}

