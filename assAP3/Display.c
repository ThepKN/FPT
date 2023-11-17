#include "Display.h"



char * IO_Message(SrecStatus_t status)
{
	return Message[status];
}

void DisplaySrec(uint8_t status, uint32_t lineNumber, SrecData_t *ptr) 
{
	//cases that need print address and data
	if (status != FILE_END && status != FILE_ERR && status != FILE_COUNT && status != FILE_ERR_S_TYPE && status != FILE_S0)
	{
		//print address
		printf("Line%d - 0x%x - ", lineNumber, ptr->Address);
		//print data with Databytes = SrecData.ByteCount - 1 - AddressNum/2
    	for (uint8_t i = 0; i < (ptr->ByteCount - ptr->SType - 2); i++) // AddressNum = (SrecData.SType + 1) * 2 => Databytes = ptr->ByteCount - ptr->SType - 2
		{
    	    printf("%02x ", ptr->pData[i]);
    	}
    	//status of line
    	if (status == FILE_OK) 
		{
    	    printf("- %s\n", IO_Message(status));
   		} 
		else 
		{
        	printf("- Line Error: %s\n", IO_Message(status));	
    	}
	}
	//case Line S0
	else if (status == FILE_S0)
	{
		printf("Line%d - %s\n", lineNumber, IO_Message(status));
	}
	//case end of file
	else if (status == FILE_END)
	{
		printf("Line%d - %s\n", lineNumber, IO_Message(status));
	}
	//other cases that dont need print address and data
	else
	{
		printf("Line%d - Line Error: %s\n", lineNumber, IO_Message(status));
	}
    


}