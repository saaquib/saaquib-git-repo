#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 32


int str_len(char ch[]);

int main()
{
	char ch_1;
	char ch[MAX];

	fgets(ch, MAX, stdin);
	*(ch + str_len(ch)) = '\0';
	if(ch == NULL)   {
		printf("\n invalid input");
		exit(0);
	}

	else if(ch == EOF)	{
                printf("\n invalid input");
                exit(0);
        }

	int num;
	int length;
	int i;

	printf("\n enter the char to be placed: ");
	scanf("%c", &ch_1);

	printf("\n enter the position at which the char to be placed: ");
	scanf("%d",&num);

	length = str_len(ch+1);
	printf("\n%d", length);
	for(i = (length - 1); i >= num; i --)
		ch[i+1] = ch[i];
	ch[num] = ch_1;
	ch[length + 1] = '\0';

	printf("\n%s",ch);

	return 0;

}

int str_len(char ch[])
{
	int count = 0;
	while(ch[count++] != '\0')  ;
	return (count-1);
}

 
