#include"header.h"

void pallindrome(char *str)
{
	int i = 0;
	int flag = 0; 
	int length;
	length = str_len(str);      
	for(i=0; i< (length / 2 ); i++){
    		if(str[i] != str[length - i - 2])
			flag++;
	}
	if(flag ==0) 
		printf("given string is palindrome");
 
	else
		printf("given string is not a palindrome");                                                                    
                                                             
}
