#include"header.h"

char* rem_sub_str(char *s1, char *s2)
{
	static int k = 0;
	int i,j;
	char *s3;
	s3 = (char*)malloc(MAX);
	int l1 = str_len(s1);
	int l2 = str_len(s2);
	/*for(i = 0; i <= l2; i++)  {
		for(j=0;j <= l1; j++)  {
			if(s2[i] == s1[j]) i++;
			else  {
				s3[k] = s1[j];
				k++;
			}
		}
	}*/
	while((*(s2 + i) != '\0') && (*(s1 + j) != '\0'))  {
		if(*(s2 + i) != *(s1 + j))  {
			*(s3 + k) = *(s1 + j);
			j++;
			k++;
		}
		else  {
			j++;
			i++;
		}
	}
	*(s3 + k) = '\0';
	return s3;
}


/*	for(i = 0; *(s1+i) != '\0'; i++)  {
		for(j = 0; *(s2+j) != '\0'; j++)  {
			if(j = l2)  j = 0;
			if(*(s2+j) == *(s1+i)) i++;
			else  {
				*(s3+k) = *(s1+i);
				k++;
			}
		}
	}
	*(s3+k) = '\0';
	*(str1 + i - len2) = '\0';
	return s3;
	*/

