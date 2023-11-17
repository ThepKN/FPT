#include<stdio.h>
#include<stdint.h>
#include <Math.h>
#ifndef _PARSE_SREC_h
#define _PARSE_SREC_h

typedef enum
{
	FILE_HEADER,
	FILE_OK,
	FILE_ERR_FORMAT,
	FILE_ERR_BYTECOUNT,
	FILE_ERR_CHECKSUM,
	FILE_NOT_EXIST,
	FILE_END
}SrecStatus;

typedef struct
{
	uint8_t Line;
	uint8_t SType;
	uint8_t ByteCount;
	uint32_t Address;
	uint8_t* pData;
	uint8_t DataBytes;
	uint8_t CheckSum; 
	SrecStatus status;
}SrecData_t;


SrecStatus SREC_OpenFile(const char*Filename);
void SREC_CloseFile();
SrecStatus SREC_ReadLine(SrecData_t* Ptr);





#endif //_PARSE_SREC_h
