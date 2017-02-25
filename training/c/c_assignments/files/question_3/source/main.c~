#include"header.h"

int main(int argc, char *argv[]) //Taking file name as argument
{
	FILE *fp;
	char ch;

	fp = fopen(argv[1],"r+"); // Opening File

	if(NULL == fp)		// Checking file opened or not   
	{
		printf("File does not exist");
		exit(0);
	}

	printf("Contents of file : \n");
	while((ch = fgetc(fp)) != EOF )  // Printing input file                                                          
	{                                                                                                         
		putc(ch,stdout);                                                        
	}
	rewind(fp);   //Making pointer to point begining of file

	while((ch = fgetc(fp)) != EOF )  
	{
		if(ch == '/')
		{
			if((ch = fgetc(fp)) == '/')
			{
				fseek(fp,-2,SEEK_CUR);
				while((ch = fgetc(fp)) != '\n')
				{
					fseek(fp,-1,SEEK_CUR);	
					ch = ' ';
					fputc(ch,fp);
				}
			}
			else 
			{	
				fseek(fp,-1,SEEK_CUR);
				if((ch = fgetc(fp)) == '*')
				{
					fseek(fp,-2,SEEK_CUR);
					putc(' ',fp);
					putc(' ',fp);
					while(((ch = fgetc(fp)) != '*') && ((ch = fgetc(fp)) != '/')) 
					{
						fseek(fp,-2,SEEK_CUR);	
						ch = ' ';
						fputc(ch,fp);
					}
					fseek(fp,-1,SEEK_CUR);
					putc(' ',fp);
					putc(' ',fp);
				}
			}
				
		}
	}

	fclose(fp);
}




								
