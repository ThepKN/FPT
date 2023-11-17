
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
	"File over memory",							//	FILE_OVER_MEMORY	= 5,
	"Data error. Input your next order:\n"		//	LIST_DATA_ERROR		= 6
};

char * IO_Message(SrecStatus_t status);

void DisplaySrec(uint8_t status, uint32_t lineNumber, SrecData_t *ptr);








#endif /* _DISPLAY_H_ */
