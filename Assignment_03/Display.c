#include "SRECParse.h"
#include"Display.h"


void Display_Line(SrecData_t* LineData)
{
	printf("Line:%d-----------------------------------------\n",LineData->Line); //testttttttttttttttttttt
	if(FILE_OK==LineData->status)
	{
	
		printf("SType=%d\n",(LineData->SType)); //testttttttttttttttttttt
		printf("ByteCount=%x\n",LineData->ByteCount); //testttttttttttttttttttt
		printf("Address=0x%x\n",LineData->Address); //testttttttttttttttttttt
		printf("Data="); //testttttttttttttttttttt
		uint8_t i=0;
		for(i=0;i<(LineData->DataBytes);i++)
		{
			printf("%02x ",LineData->pData[i]); //testttttttttttttttttttt
		}
		printf("\n");
		printf("CheckSum=%x\n",LineData->CheckSum); //testttttttttttttttttttt
	};
}

char * Message[] = {
	"Header",
	"TRUE",			
	"Format error",			
	"Byte Count error",						
	"Checksum error" ,
	"File does not exist",
	"End of file"
};

char * Display_Message(SrecStatus status)
{
	return Message[status];
}
