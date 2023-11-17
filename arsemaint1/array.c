#include "array.h"
#include "IO.h"

static uint32_t ArrayData[100];
static uint8_t Len = 0;
static uint8_t temp;

StatusType Array_Create()
{
	StatusType status = ARRAY_SUCCESSFUL;	//command successful
	
	if (Len != 0)// Check if array had elements, clear data of old array
	{
		for (int i = 0; i < Len; i++)
		{
        	ArrayData[i] = 0;
    	}
	}
	
	Len = IO_numberElements();//input number of elements
	Input_ArrayData(ArrayData, Len);//input elements of array
	
	return status;
}

StatusType Array_Print()
{
	StatusType status = ARRAY_EMPTY;		// Array empty
	
	if (Len != 0)
	{
		Output_ArrayData(ArrayData, Len);
		status = ARRAY_PRINT;			//print succesful
	}
	
	return status;
}

StatusType Array_Insert(uint32_t Data)
{
	StatusType status = ARRAY_FULL;		// Full Array
	
	if (Len < 100)
	{
		ArrayData[Len] = Data;
		Len++;
		status = ARRAY_SUCCESSFUL;
	}

	return status;
}

StatusType Array_Delete(uint8_t k)
{
	StatusType status = ARRAY_OUT_OF_RANGE;		// Invalid Index
	
	if (Len == 0)
	{
		status = ARRAY_EMPTY;
		return status;
	}
	
	if (k < Len)
	{
		for (int i = k; i < (Len - 1); i++)
		{
			ArrayData[i] = ArrayData[i + 1];
		}
		Len--;
		status = ARRAY_SUCCESSFUL;
	}
	
	return status;
}

StatusType Array_AscenSort()
{
	StatusType status = ARRAY_EMPTY;
	
	if (Len != 0)
	{
		for (int i = 0; i < (Len - 1); i++)
		{
			for(int j = i + 1; j < Len; j++)
			{
				if (ArrayData[i] > ArrayData[j]) // compare and swap number in array
				{
					temp = ArrayData[i];
					ArrayData[i] = ArrayData[j];
					ArrayData[j] = temp;
				}	
			}
		}
		status = ARRAY_SUCCESSFUL;
	}
	
	return status;
}


StatusType Array_DescenSort()
{
	StatusType status = ARRAY_EMPTY;
	
	if (Len != 0)
	{
		for (int i = 0; i < (Len - 1); i++) 
		{
			for(int j = i + 1; j < Len; j++)
			{
				if (ArrayData[i] < ArrayData[j]) // compare and swap number in array
				{
					temp = ArrayData[i];
					ArrayData[i] = ArrayData[j];
					ArrayData[j] = temp;
				}	
			}
		}
		status = ARRAY_SUCCESSFUL;
	}
	
	return status;
}

StatusType Array_Search(uint32_t x)
{
	StatusType status = ARRAY_FALSE;		//x is not in array
	
	if (Len == 0)
	{
		status = ARRAY_EMPTY;
		return status;
	}
	
	for (int i = 0; i < Len; i++)
	{
		if (ArrayData[i] == x)
		{
			status = ARRAY_TRUE;		//x is in array
		}
	}
	
	return status;
}

StatusType Array_Choose()
{
	StatusType status = ARRAY_CHOOSE;		//choose the function again
	
	return status;
}

StatusType Array_Quit()
{
	StatusType status = ARRAY_QUIT;		//quit program
	
	return status;
}

