#include<stdio.h>
#include<stdint.h>
#include "SRECParse.h"
#include<assert.h>
#include"Display.h"
SrecStatus Status;
SrecData_t TempData;
SrecData_t* PtrTemp=&TempData;
void main()

{
	//open file
	const char* filename ="blinkLed.srec";
	Status = SREC_OpenFile(filename);
	printf("%s\n",Display_Message(Status));
	
	//read line
	while(Status!=FILE_END)
	{
		Status=SREC_ReadLine(PtrTemp);
		Display_Line(PtrTemp);
		printf("%s\n",Display_Message(Status));
	};
	
	//close file
	if(Status!=FILE_END)
	{
		SREC_CloseFile();
	};
	
}
