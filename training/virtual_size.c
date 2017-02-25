//finding the amount of virtual address through program
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
double my_atoi(char *string);
double power_1(double,double);
int main()
{
	FILE *fp;
	//int pid_number;
	char ch;
	//char *string;

	char *buf1;
	char *buf2;
	char *buf3;
	char *difference;
	char *result;
	int i;

	int j;

	double a;
	double b;
	double c;

	//	pid_number = getpid();
	//	printf("%d\n",pid_number);

	if(NULL == (buf1 = (char *)malloc(sizeof(char)*32))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (buf2 = (char *)malloc(sizeof(char)*32))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (difference = (char *)malloc(sizeof(char)*32))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (result = (char *)malloc(sizeof(char)*32))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if(NULL == (buf3 = (char *)malloc(sizeof(char)*32))){
		perror("malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if((fp = fopen("/proc/2539/maps","r")) == NULL)
	{
		perror("file cant open\n");
		exit(0);
	}

	while((ch = fgetc(fp)) != EOF)
	{
		printf("%c",ch);
	}
	rewind(fp);

	while((ch = fgetc(fp) != EOF)) {

				fseek (fp, -1, SEEK_CUR);

			i = 0;
			while((ch = fgetc(fp)) != '-')
			{
				*(buf1 + i) = ch;
				i++;
			}
			printf("%s\t",buf1);
			a = my_atoi(*buf1);
			printf("%ld\n", a);
			j = 0;	
				
			while((ch = fgetc(fp)) != ' ')
			{
		
				*(buf2 + j) = ch;
				j++;
			}
			printf("%s\n",buf2);
	//		b = my_atoi(*buf2);
			
	//		c = b - a;
	//		printf("%ld\n",c);
			while ((ch= fgetc(fp)) != '\n');
			//fseek (fp, -1, SEEK_CUR);
			//if ((ch = fgetc(fp)) == ' ')
			//	break;
			//1}
		//	difference = buf2 - buf1;
		//	printf("%d\n",*difference);
			//c = b - a;
		//	printf("%x\n",c);
	}
	fclose(fp);

	return 0;
}
double my_atoi(char *string)
{
	double decimalNumber = 0;
	int i = 0;
	int j = 0;
	char hexDigits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
      '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	double power = 0;
	double base = 16;
/*	int n;
	string = (char*)malloc(sizeof(char)*30);
	while((*(string + i) >= '0') && (*(string + i) <= '9'))
	{
		n = n * 10 + (*(string + i));
		i++;
	}
	return n;*/
	 /* Converting hexadecimal number to decimal number */
	printf("%d\n", strlen(string));
    for(i=strlen(string)-1; i >= 0; i--) {
        /*search currect character in hexDigits array */
        for(j=0; j<16; j++){
            if(*(string + i) == hexDigits[j]){
                decimalNumber += j*power_1(base, power);
            }
        }
        power++;
    } 
	return decimalNumber;
}
double power_1(double base,double power)
{
	int result = 1;
	while( power != 0)
	{
		result *= base;
		power--;
	}
	return result;
}
