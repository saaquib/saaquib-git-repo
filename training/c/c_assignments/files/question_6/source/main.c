#include"header.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	struct EH a[2];
	int i;

	fp = fopen(argv[1],"r+");
	for(i = 0; i < 2; i++)
	{
		fread(&a[i],sizeof(struct EH),1,fp);
		printf("\n%s \n%hi \n%hi \n%d \n%u",a[i].e_ident,a[i].e_type,
								a[i].e_machine,a[i].e_version,a[i].e_entry);
	}
 
	return 0;
}
