
#include "Display.h"



char * IO_Message(SrecStatus_t status)
{
	return Message[status];
}

void DisplaySrec(uint8_t status, uint32_t lineNumber, SrecData_t *ptr)
{
    printf("Line%d - 0x%x - ", lineNumber, ptr->Address);


    for (uint8_t i = 0; i < ptr->ByteCount - 1; i++)
	{
        printf("%02x ", ptr->pData[i]);
    }

    if (status == FILE_OK)
	{
        printf("- %s\n", IO_Message(status));
    }
	else
	{
        printf("- Line Error: %s\n", IO_Message(status));
    }
}
