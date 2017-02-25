#include"header.h"

int main(int argc, char *argv[])
{
	int i;
	printf("\n the number of files in a folder are : %d\n", argc - 1);
	printf("files are \n");
	for(i = 1;i < argc; i++)	
		printf("\n%d . %s",i,argv[i]);

	return 0;
}
