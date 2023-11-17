#include <stdio.h>
#include <stdlib.h>
#include "ParseSrec.h"
int main()
{    //SrecStatus_t status;
/*while(fscanf(fileptr, "%s",status )!=-1 )
{

    status = SREC_OpenFile("blinkLed.txt");
    printf("%d ", status);

    status = SREC_ReadLine();
    printf("%d", status);
    SREC_CloseFile();
}
fclose(fileptr);*/
SrecStatus_t status = 1;
	uint32_t lineNumber = 0;
	status = SREC_OpenFile("test.srec");
	printf("%d\n", status);
status = SREC_ReadLine();
	lineNumber++;
	DisplaySrec(status, lineNumber, getSrecData());
}
