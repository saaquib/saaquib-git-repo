#include"header.h"
int is_valid(char s[])
{
        int i;
        int n = 0;

        for(i =0; i < strlen(s); i++)  {
                if(((s[i] >= '0') && (s[i] <= '9')) || (s[i] == '-') || (s[i] == ' ') || (s[i] == '\n')) {
                        if((s[i] != '-') && (s[i] != ' ' ) && (s[i] != '\n'))
                                n = n * 10 + (s[i] - '0');
                }
                else  {
                        printf("\n Invalid input ");
                        exit(0);
                }
        }
        if(s[0] == '-')
                return ((~n) + 1);
        else
                return n;

        if(s[i] == ' ')
                ;
        else return n;

         if(s[i] == '\n')
                ;
        else return n;
}
