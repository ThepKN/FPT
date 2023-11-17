#include <stdio.h>
#include <stdlib.h>
#include "ParseSrec.h"
#include "Display.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	SrecStatus_t status;
	uint32_t lineNumber = 0;

	//open file
	status = SREC_OpenFile("blinkLed.txt");
	printf("Open File %s\n", IO_Message(status));

	//read and print each line
	while (status != FILE_ERR && status != FILE_END)
	{
		status = SREC_ReadLine();
		lineNumber++;
		DisplaySrec(status, lineNumber, getSrecData());
	}

	SREC_CloseFile();

	return 0;
}
