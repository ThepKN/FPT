#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <stdio.h>
#include "ParseSrec.h"
static char * Message[] = {
	"OK\n",										//	LIST_OK				= 0,
	"Error Format\n",							//	FILE_ERR_FORMAT 	= 1,
	"Error Byte Count\n",						//	FILE_ERR_BYTECOUNT 	= 2,
	"Error Checksum\n",							//	FILE_ERR_CHECKSUM  	= 3,
	"File does not exist\n",					//  FILE_NOT_EXIST		= 4,
	"File over memory\n",						//	FILE_OVER_MEMORY	= 5,
	"File error\n",								//	FILE_ERR			= 6,
	"End of File\n",							//	FILE_END			= 7,
	"No need this line\n",						//	FILE_COUNT			= 8,
	"Error format of S_Type\n",					//	FILE_ERR_S_TYPE		= 9,
	"Line S0\n"									//	FILE_S0				= 10
};

char * IO_Message(SrecStatus_t status);

void DisplaySrec(uint8_t status, uint32_t lineNumber, SrecData_t *ptr);








#endif /* _DISPLAY_H_ */