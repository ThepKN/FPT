
#include <stdio.h>
#include "array.h"

void Menu()//menu of functions when start program
{
	printf("-----ARRAY MANAGEMENT PROGRAM-----\n\n");
	printf("Please choose the following functions:\n");
	printf("'c' - Create an array of integer sequence\n");
	printf("'p' - Print the sequence\n");
	printf("'i' - Add an element to the last of the sequence\n");
	printf("'d' - Delete an element at the Kth position\n");
	printf("'s' - Arrange the sequence in ascending order\n");
	printf("'x' - Arrange the sequence in descending order\n");
	printf("'t' - Search for a number x in the sequence\n");
	printf("'e' - Quit Program\n\n");
	printf("Before starting, please take note:\n");
	printf("- While chosing function, if you input more than one character, only the first character will be recorded\n");
	printf("- If you enter a real number, we will only take the integer value\n\n");
}

static char * Message[] = {
	"Index is out of range. Input your next order:\n",							//	ARRAY_OUT_OF_RANGE	= 0,
	"Command Successfully. Input your next order:\n",							//	ARRAY_SUCCESSFUL 	= 1,
	"Sorry, Array is empty now. Input your next order:\n",						//	ARRAY_EMPTY 		= 2,
	"Array is Full. Input your next order:\n",									//	ARRAY_FULL  		= 3,
	"Thanks for using program. See you next time\n",							//  ARRAY_QUIT			= 4,
	"There is no number x in the sequence. Input your next order:\n",			//	ARRAY_FALSE			= 5,
	"Number x is in the sequence. Input your next order:\n",					//	ARRAY_TRUE			= 6,
	"\nPrint successfully. Input your next order:\n",							//	ARRAY_PRINT			= 7,
	"Please choose the right function\n"										//	ARRAY_CHOOSE		= 8,

};

static char * Guide[] = {
	"Please input the Data(number of elements) you want to create\n",								//	GUIDE_CREATE	= 0,
	"Please input the Data(number) that you want to insert to the last of the sequence\n",			//	GUIDE_INSERT 	= 1,
	"Please input the Data(kth index of element) that you want to delete\n",								//	GUIDE_DELETE 	= 2,
	"Please input the Data(number x) that you want to find in sequence\n"										//	GUIDE_SEARCH  	= 3,
	
};

int IO_numberElements()
{
	int num, result;
	
	fflush(stdin);
	printf("The number of elements should be less than 100\n");
	//using unlimited loop to check the condition of num, must be integer and <100
	while(1)			
	{
		printf("Input the Data: ");
		result = scanf("%d", &num);
	
		if ((result == 1) && (num > 0 && num < 100))
		{
			break;
		}
		else
		{
			fflush(stdin);
			printf("Invalid Data. Please input again a valid Data\n");
		}
	}
	
	return num;
}

int IO_userInput()
{
	int num, result;
	
	fflush(stdin);
	while(1)
	{
		printf("Input the Data: ");
		result = scanf("%d", &num);
	
		if (result == 1)
		{
			break;
		}
		else
		{
			fflush(stdin);
			printf("Invalid Data. Please input again a valid Data\n");
		}
	}
	
	return num;
}

/*
 * Input - status of array function
 * Output - Message for user
 */
char * IO_Message(StatusType status)
{
	return Message[status];
}

/*
 * Input - condition of guide
 * Output - Guide Message for user
 */
char * Guide_Message(GuideType condition)	
{
	return Guide[condition];
}

/*
 * Input - array ArrayData, len
 */
void Input_ArrayData(int ArrayData[], int Len)
{
	printf("An array with %d elements will be created right now\n", Len);
	printf("The elements of the array are:\n");
	for (int i = 0; i < Len; i++)
		scanf("%d", &ArrayData[i]);
}

/*
 * Input - array ArrayData, len
 * Output - array
 */
void Output_ArrayData(int ArrayData[], int Len)
{
	for (int i = 0; i < Len; i++)
		printf("%d ", ArrayData[i]);
}

