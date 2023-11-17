#ifndef _PARSE_SREC_H_
#define _PARSE_SREC_H_

#include <stdint.h>

#define HEX_INVALID			0XFF

typedef enum
{
	FILE_OK				= 0x0U,
	FILE_ERR_FORMAT		= 0x1U,
	FILE_ERR_BYTECOUNT	= 0x2U,
	FILE_ERR_CHECKSUM	= 0x3U,
	FILE_NOT_EXIST		= 0x4U,
	FILE_OVER_MEMORY	= 0x5U,
	FILE_ERR			= 0x6U,
	FILE_END			= 0x7U,
	FILE_COUNT			= 0x8U,
	FILE_ERR_S_TYPE		= 0x9U,
	FILE_S0				= 0xAU
} SrecStatus_t;

typedef enum
{
	FIRST_LINE_OK		= 0x0U,
	FIRST_LINE_FALSE	= 0x1U
} FirstLineStatus_t;

typedef struct 
{
	uint8_t SType;			// 0/1/2/3//..7/8/9
	uint8_t ByteCount;
	uint32_t Address;
	uint8_t * pData;		// Dynamic allocate
	uint8_t CheckSum;
} SrecData_t;


static uint8_t ChartoHex(uint8_t character);
static SrecStatus_t StrtoHex(uint8_t * pStr, uint8_t len, uint32_t * pResult);
static SrecStatus_t Check_CheckSum(void);
SrecStatus_t SREC_OpenFile(const char * filename);
void SREC_CloseFile();
SrecStatus_t SREC_ReadLine();
SrecData_t * getSrecData();

//extern SrecData_t SrecData;
#endif	/* _PARSE_SREC_H_ */

