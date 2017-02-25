#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h> 


long double my_atoi(char *str);                                                  

int valid(char *str);

int main(void)
{
	char ch;                                                                    
    int k = 1;                                                                  
    char *buf1;                                                                 
    char *buf2;                                                                 
    char *difference;                                                           
    char *result;                                                               
    int i;                                                                      
    int j;      
	char name[100];                              
	float total = 0;                                  
                                                                                
    long double a;                                                              
    long double b;                                                              
    long double c = 0; 


	DIR *d;
	FILE *fp;
    struct dirent *dir;
	                                                                            
    if (NULL == (buf1 = (char *)malloc(sizeof(char)*32))){                       
        perror("malloc failed\n");                                              
        exit(EXIT_FAILURE);                                                     
    }
                                                                           
    if (NULL == (buf2 = (char *)malloc(sizeof(char)*32))){                       
        perror("malloc failed\n");                                              
        exit(EXIT_FAILURE);                                                     
    }
                                                                           
    if (NULL == (difference = (char *)malloc(sizeof(char)*32))){                 
        perror("malloc failed\n");                                              
        exit(EXIT_FAILURE);                                                     
    }                       

	if (NULL == (result = (char *)malloc(sizeof(char)*32))){                       
        perror("malloc failed\n");                                              
        exit(EXIT_FAILURE);                                                     
    } 
  
	d = opendir("/proc");
  	if (d) {
	    while ((dir = readdir(d)) != NULL) {
     		// printf("%s\n", dir->d_name);
			if(valid(dir -> d_name)) {
			//strcpy(name, "sudo");
				strcpy(name, "/proc/");
				strcat(name, dir -> d_name);
				strcat(name, "/maps");
	
				if(NULL != (fp = fopen(name,"r"))) {
					 while((ch = fgetc(fp)) != EOF) {                                                                       
            			//	printf("%c",ch);                                                    
        			}                                                                       
        		
					rewind(fp);                                                             
                                                                                
       	 			while((ch = fgetc(fp) != EOF)) {                                        
            			fseek (fp, -1, SEEK_CUR);                                           
                   		i = 0;                                                              
            			while((ch = fgetc(fp)) != '-') {                                                                   
                			*(buf1 + i) = ch;                                               
                			i++;                                                            
            			}                                                                   
            	
						*(buf1+i) = '\0';                                                   
           			 	//	printf("%s\t",buf1);                                                
            			a = my_atoi(buf1);                                                  
            			j = 0;                                                              
                                                                                
           			 	while((ch = fgetc(fp)) != ' ') {                                                                   
               			 	*(buf2 + j) = ch;                                               
                			j++;                                                            
            			}     
                                                              
            			*(buf2+j) = '\0';                                                   
    	        		//	printf("%s\n",buf2);                                                
	           			b = my_atoi(buf2);                                                  
	            		c += b - a;                                                    
            	
						while ((ch= fgetc(fp)) != '\n');
					}
                                    
					c = (float)c/(1024*1024);   
					total += c;                                                
	    			printf("%s = %f MB\n",dir -> d_name, (float)c);                                       
    				fclose(fp);
                                                                                
       			 }
			}    
		}
    	closedir(d);
 	 }
	
	 printf("total virtual address:%f MB\n",total);
	 return(0);
}






long double my_atoi(char *str)                                                  
{                                                                               
    long double num = 0;                                                        
    int i = 0;                                                                  
                                                                                
    while(*(str+i)!='\0') {                                                     
        if(*(str+i) >= '0' && *(str+i)<='9') {                                  
            num = (num*16) + *(str+i) - '0';                                    
        }                                                                       
        else if (*(str+i) >= 'a' && *(str+i) <= 'f') {                          
            num = num * 16 + *(str+i) - 87;                                     
        }                                                                       
        i++;                                                                    
    }                                                                           
    return num;                                                                 
}                                                                               
                                                                                
int valid(char *str)                                                            
{                                                                               
    int i = 0;                                                                  
         while(*(str+i)!='\0') {                                                
            if(!(*(str+i) >= '0' && *(str+i)<='9'))                             
                return 0;                                                       
            i++;                                                                
        }                                                                       
    return 1;                                                                   
}     
