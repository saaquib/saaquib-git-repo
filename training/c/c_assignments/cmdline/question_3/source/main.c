#include "header.h"

int main(int argc,char *argv[])
{
	char *num1 = (char *)malloc(MAX*sizeof(char));
	char *num2 = (char *)malloc(MAX*sizeof(char));
	int number1;
	int number2;	
	char *ch = argv[1];

	num1 = argv[2];
	num2 = argv[3];
	
	printf("%s : ",ch);
	number1 = is_valid(num1);
	printf("%d",number1);
	number2 = is_valid(num2);
	
	if(strcmp(ch,"add") == 0)
	fptr = add1;

	else if(strcmp(ch,"sub") == 0)
        fptr = sub1;

	else if(strcmp(ch,"mul") == 0)
        fptr = mul1;
	
	else if(strcmp(ch,"div") == 0)
        fptr = div1;
	
	else{
	printf("invalid\n");
	return 0;
	}
	printf("\nResult is: %d ",fptr(number1,number2));

	return 0;
}







