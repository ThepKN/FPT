// Console_IO


//typedef enum
//{

//} StatusType;

static char * Message[] = {
	"Index is out of range",	//	ARRAY_OUT_OF_RANGE	= 0,
	"Command Successfully",		//	ARRAY_SUCCESSFUL 	= 1,
	"Array is Empty",			//	ARRAY_EMPTY 		= 2,
	"Array is Full"				//	ARRAY_FULL  		= 3
	
};

//IO_UserInput()


/*
 * Input - status of array function
 * Output - Message for user
 */
char * IO_Message(ListStatusType status)
{
	return Message[status];
}


