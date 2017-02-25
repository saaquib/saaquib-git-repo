#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma pack (1)

struct frame1 
{

	unsigned char HEC;
	unsigned char CLP:1;
	unsigned char PTI:3;
	unsigned char VCI;
	unsigned char VPI;
	unsigned char GFC:4;
};

struct frame2
{
	unsigned short int SourcePort;
	unsigned short int DestinationPort;
	unsigned int SequenceNumber;
	unsigned int AcknowledgeNumber;
	unsigned short int HeaderLength : 4;
	unsigned short int Reserved : 6;
	unsigned short int CodeBit : 6;
	unsigned short int Window;
	unsigned short int Checksum;
	unsigned short int Urgent;
	unsigned char data[];
	
};	

struct frame3
{
	unsigned short int Version : 4;
	unsigned short int HeaderLength : 4;
	unsigned short int ServiceType : 4;
	unsigned short int TotalLength;
	unsigned short int Identification;
	unsigned short int Flags : 3;
	unsigned short int FragmentOffset : 12;
	unsigned char TTL;
	unsigned char Protocol;
	unsigned short int HeaderChecksum;
	unsigned int SourceIPAddr;
	unsigned int DestinationIPAddr;
	unsigned int Option : 19;
	unsigned int Padding : 12;
};




