#include "Device.h"

static char * Message[] = {
	"Command Successfully. Input your next order:\n",									//	LIST_OK				= 0,
	"Sorry, your position is out of range. Input your next order:\n",					//	LIST_OUT_OF_RANGE 	= 1,
	"Over memory. Input your next order:\n",											//	LIST_OVER_MEMORY 	= 2,
	"Please choose the right function\n",												//	LIST_CHOOSE  		= 3,
	"Thanks for using program. See you next time\n",									//  LIST_QUIT			= 4,
	"There is no list of Device. Before adding device, please create Device list\n",	//	LIST_NOT_EXIST		= 5,
	"Data error. Input your next order:\n"												//	LIST_DATA_ERROR		= 6
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


