#include<stdio.h>
#include<string.h>
struct employ                                                               
    {                                                                           
        int id;                                            				
		char name[20];                                                  
		char batch[10];
	}; 
struct employ e[3];
int main()
{
/*	int i;
	for(i = 0;i < 3;i++ )  {
		e[i].id = fgetc(stdin);
		fgets(e[i].name, 20,stdin);
		fgets(e[i].batch, 20,stdin);
	}
//			scanf("%d%s%s",&e[i].id,&e[i].name,&e[i].batch);

//		printf("\n id   	name            		batch");*/
	struct employ b ={1, "saaq", "cr17"};
	struct employ c;
	c.id = 10;
	strcpy(c.name, "kasai");
	strcpy(c.batch,"cr17");
//	for(i = 0; i < 3; i++)
		printf("%d\n%s\n%s",c.id,c.name,c.batch);
		printf("%d\n%s\n%s",b.id,b.name,b.batch);
		printf("\n");
	return 0;
}
