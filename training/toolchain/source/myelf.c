#include"myelfheader.h"

int main(int argc, char *argv[])
{
	int i;
	int string;
	char buffer[MAX];
	FILE *fp;
	MyElf32_Ehdr ELF;
	MyElf32_Shdr *SELF;
	MyElf32_Shdr SELF2;
	SELF = (MyElf32_Shdr *) malloc (sizeof(MyElf32_Shdr));
	fp = fopen ( argv[1],"r");
	perror (argv[1]);
	printf("\n-----------------------------------------------------------------------------------------\n");
	printf("ELF HEADER")	;
	printf("\nMAGIG\t\t\t\t:\t\t\t\t");
	fread (&ELF, 52, 1, fp);
	for (i = 0; i < EI_NIDENT; i++) {
		printf("%x ",ELF.e_myident[i]);
	}
	printf("\nCLASS\t\t\t\t:\t\t\t\t");
	switch (ELF.e_myident[4]) {
		case 0: printf("Invalid Class\n");
				break;
		case 1: printf("ELF32\n");
				break;
		case 2: printf("ELF64\n");
				break;
	}
	printf("DATA\t\t\t\t:\t\t\t\t");
	switch (ELF.e_myident[5]) {
		case 0: printf("Invalid Data Encoding\n");
				break;
		case 1: printf("2's compliment, little endian\n");
				break;
		case 2: printf("2's compliment, big endian\n");
				break;
	}
	printf("VERSION\t\t\t\t:\t\t\t\t");
	switch (ELF.e_myident[6]) {
		case 0: printf("Invalid Version\n");
				break;
		case 1: printf("%d (current)\n",ELF.e_myident[6]);
				break;
	}
	printf("OS/ABI\t\t\t\t:\t\t\t\t");
	switch (ELF.e_myident[7]) {
		case 0: printf("Invalid Version\n");
				break;
		case 1: printf("Unix System V ABI\n");
				break;
		default : printf("others\n");
				break;
	}
	printf("ABI VERSION\t\t\t:\t\t\t\t");
	printf("%d\n",ELF.e_myident[8]);
	printf("TYPE\t\t\t\t:\t\t\t\t");
	switch (ELF.e_mytype) {
		case 0: printf("Unknown Type\n");
				break;
		case 1: printf("A relocatable file\n");
				break;
		case 2: printf("An executable file\n");
				break;
		case 3: printf("A shared file\n");
				break;
		case 4: printf("A core file\n");
				break;
	}
	
	printf("MACHINE\t\t\t\t:\t\t\t\t");
	switch (ELF.e_mymachine) {
		case 0: printf("Unknown machine\n");
				break;
		case 1: printf("AT&T WE 32100\n");
				break;
		case 2: printf("Sun Microsystem SPARC\n");
				break;
		case 3: printf("Intel 80386\n");
				break;
		default: printf("others\n");
				break;
	}
	printf("VERSION\t\t\t\t:\t\t\t\t");
	printf("%d\n",ELF.e_myident[6]);
	printf("ENTRY POINT ADDRESS\t\t:\t\t\t\t");
	printf("%0x \n",ELF.e_myentry);
	printf("START OF PROGRAM HEADER\t\t:\t\t\t\t");
	printf("%d (bytes into file)\n",ELF.e_myphoff);
	printf("START OF SECTION HEADER\t\t:\t\t\t\t");
	printf("%d (bytes into file)\n",ELF.e_myshoff);
	printf("FLAGS\t\t\t\t:\t\t\t\t");
	printf("0x%d \n",ELF.e_myflags);
	printf("SIZE OF THIS HEADER\t\t:\t\t\t\t");
	printf("%d (bytes)\n",ELF.e_myehsize);
	printf("SIZE OF PROGRAM HEADER\t\t:\t\t\t\t");
	printf("%d (bytes) \n",ELF.e_myphentsize);
	printf("NUMBER OF PROGRAM HEADER\t:\t\t\t\t");
	printf("%d \n",ELF.e_myphnum);
	printf("SIZE OF SECTION HEADER\t\t:\t\t\t\t");
	printf("%d (bytes) \n",ELF.e_myshentsize);
	printf("NUMBER OF SECTION HEADER\t:\t\t\t\t");
	printf("%d \n",ELF.e_myshnum);
	printf("SECTION HEADER STRING TABLE INDEX:\t\t\t\t");
	printf("%d \n",ELF.e_myshstrndx);
	
	string = ELF.e_myshoff + ( ELF.e_myshentsize * ELF.e_myshstrndx );
	fseek (fp,string,SEEK_SET );
	fread ( &SELF2, sizeof(SELF2), 1, fp );
	fseek (fp , SELF2.sh_myoffset, SEEK_SET);
	fread ( buffer, SELF2.sh_mysize, 1, fp );
	printf("-----------------------------------------------------------------------------------------\n");
	printf("SECTION HEADER\n");
	printf("[Nr]  Name\t\t\t\t\t\tType\t\tAddr\t  Off\t  Size\t  ES\tFlg\tLk\tInf\tAl\n");
	fseek(fp, ELF.e_myshoff, SEEK_SET);
	for(i = 0; i < ELF.e_myshnum; i++) {

		fread(SELF, sizeof(*SELF), 1, fp); 

		printf("[%2d] ", i);
		printf(" %-18s\t\t\t", (buffer + SELF->sh_myname));

		switch( SELF -> sh_mytype ) {
			case 0 :	printf("\tNULL\t"); 
					break;
			case 1 :	printf("\tPROGBITS");
					break;
			case 2 :	printf("\tSYSTAB\t");
					break;
			case 3 :	printf("\tSTRTAB\t");
					break;
			case 4 :	printf("\tRELA\t");
					break;
			case 5 :	printf("\tHASH\t");
					break;
			case 6 :	printf("\tDYNAMIC\t");
					break;
			case 7 :	printf("\tNOTE\t");
					break;
			case 8 :	printf("\tNOBITS\t");
					break;
			case 9 :	printf("\tREL\t");
					break;
			case 10 :	printf("\tSHLIB");
					break;
			case 11 :	printf("\tDYNSYS\t");
					break;
			case 0x70000000 :printf("\tLOPROC");
					break;
			case 0x7fffffff :printf("\tHIPROC");
					break;
			case 0x80000000 :printf("\tLOUSER");
					break;
			case 0xffffffff :printf("\tHIUSER");
					break;
			default :	printf("\tinvalid\t");
					break;
		}

		printf("\t%08x  ", SELF -> sh_myaddr);
		printf("%06x",SELF -> sh_myoffset);
		printf("  %06x",SELF -> sh_mysize); 
		printf("  %02d\t",SELF -> sh_myentsize); 
		switch(SELF -> sh_myflags) {
			case 0x2 : printf ("A\t");
					   break;

			case 0x6 : printf ("AX\t");
					   break;
			case 0x3 : printf ("WA\t");
					   break;
			case 0x30 : printf("MS\t");
						break;
			default : printf ("\t");
		}
		printf("%2d\t",SELF -> sh_mylink); 
		printf("%2d\t", SELF -> sh_myinfo); 
		printf("%2d\n", SELF -> sh_myaddralign);  
	}
		printf("\n-----------------------------------------------------------------------------------------\n");
	fclose(fp);
	return 0;
}



