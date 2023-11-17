#ifndef _PARSE_SREC_H_
#define _PARSE_SREC_H_

#include <stdint.h>

#define HEX_INVALID			0XFF

typedef enum
{
	FILE_OK				= 0x0U,
	FILE_ERR_FORMAT		= 0x1U,
	FILE_ERR_BYTECOUNT  = 0x2U,
	FILE_ERR_CHECKSUM   = 0x3U,
	FILE_NOT_EXIST      = 0x4U,
} SrecStatus_t;

typedef struct
{
	uint8_t SType;			// 0/1/2/3//..7/8/9
	uint8_t ByteCount;
	uint32_t Address;
	uint8_t * pData;		// Dynamic allocate
	uint8_t CheckSum;
} SrecData_t;

#endif	/* _PARSE_SREC_H_ */

