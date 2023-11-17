#include <stdio.h>
#include "array.h"
#include "IO.h"
#include <stdint.h>

int main()
{
	StatusType status;
	GuideType condition;
	char inputChar;
	
	Menu();
	
	do
	{
		// 1. User Input from Keyboard
		scanf("%c", &inputChar);
		
		// 2. Call Array Management Function
		switch(inputChar)
		{
			case 'c':
			 	condition = GUIDE_CREATE;
			 	printf("%s", Guide_Message(condition));//guide message before calling Array Management function
				status = Array_Create();
				break;	
			case 'p':
				status = Array_Print();
				break;
			case 'i':
				condition = GUIDE_INSERT;
				printf("%s", Guide_Message(condition));
				status = Array_Insert(IO_userInput());
				break;
			case 'd':
				condition = GUIDE_DELETE;
				printf("%s", Guide_Message(condition));
				status = Array_Delete(IO_userInput());
				break;
			case 's':
				status = Array_AscenSort();
				break;
			case 'x':
				status = Array_DescenSort();
				break;
			case 't':
				condition = GUIDE_SEARCH;
				printf("%s", Guide_Message(condition));
				status = Array_Search(IO_userInput());
				break;
			case 'e':
				status = Array_Quit();
				break;
			default:
				status = Array_Choose();
		}
		
		// 3. Display Message Status
		printf("%s", IO_Message(status));
		fflush(stdin);
	} while (inputChar != 'e');
	
	return 0;
}

