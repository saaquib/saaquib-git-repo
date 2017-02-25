#include<stdio.h>
#include<features.h>
#include<unistd.h>
#include<stdint.h>
#include<stdlib.h>
#define MAX 1000
/*Type for a 16 - bit quantity: */
typedef uint16_t MyElf32_Half;

/*Type for signed int and unsigned int 32-bit quantities: */
typedef uint32_t MyElf32_Word;
typedef int32_t MyElf32_Sword;

/*Type for signed int and unsigned int 64-bit quantities: */

/*Type of addresses. */
typedef uint32_t MyElf32_Addr;

/*Type of file offsets. */
typedef uint32_t MyElf32_Off;


/*Type for section indices, which are 16-bits quantities. */
typedef uint16_t MyElf32_Section;
typedef MyElf32_Half MyElf32_Versym;

/* MyELF file header. This header will be present at the begining of every ELF file. */

#define EI_NIDENT (16)

typedef struct {
	unsigned char e_myident[EI_NIDENT];
	MyElf32_Half e_mytype;
	MyElf32_Half e_mymachine;
	MyElf32_Word e_myversion;
	MyElf32_Addr e_myentry;
	MyElf32_Off e_myphoff;
	MyElf32_Off e_myshoff;
	MyElf32_Word e_myflags;
	MyElf32_Half e_myehsize;
	MyElf32_Half e_myphentsize;
	MyElf32_Half e_myphnum;
	MyElf32_Half e_myshentsize;
	MyElf32_Half e_myshnum;
	MyElf32_Half e_myshstrndx;
}MyElf32_Ehdr;


typedef struct {
	uint32_t   sh_myname;
        uint32_t   sh_mytype;
        uint32_t   sh_myflags;
        MyElf32_Addr sh_myaddr;
        MyElf32_Off  sh_myoffset;
        uint32_t   sh_mysize;
        uint32_t   sh_mylink;
        uint32_t   sh_myinfo;
        uint32_t   sh_myaddralign;
        uint32_t   sh_myentsize;
}MyElf32_Shdr;
