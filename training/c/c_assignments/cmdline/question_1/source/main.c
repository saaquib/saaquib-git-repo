#include"header.h"
#include<unistd.h>
int main(int argc, char *argv[])
{
#if 1
	int i;
	FILE * fp;
	printf("\n the number of files in a folder are : %d\n", argc - 1);
	printf("files are \n");
	
	if(argc < 2){
		puts("\n no input givenExecute as:\n"
					"./exec *\n");
	}
	else
	{
		for(i = 1;i < argc; i++){	
			if(!(fp = (fopen(argv[i], "r")))){
				puts("Execute as : ./exec *\n");
				return 0;
			}
			fclose(fp);
		}
		for(i = 1;i < argc; i++)	
			printf("\n%d . %s",i,argv[i]);
	
		putchar(10);
	}
#endif
//	execlp("ls", "ls ", "-lrt", (void*)NULL);
	return 0;
}
