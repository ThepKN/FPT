#include <stdint.h>
#include <stdlib.h>

typedef enum
{
	ARRAY_OUT_OF_RANGE	= 0,
	ARRAY_SUCCESSFUL 	= 1,
	ARRAY_EMPTY 		= 2,
	ARRAY_FULL  		= 3,
	ARRAY_QUIT			= 4,
	ARRAY_FALSE			= 5,
	ARRAY_TRUE			= 6,
	ARRAY_PRINT			= 7,
	ARRAY_CHOOSE		= 8
} StatusType;		// Data Types

typedef enum
{
	GUIDE_CREATE		= 0,
	GUIDE_INSERT	 	= 1,
	GUIDE_DELETE 		= 2,
	GUIDE_SEARCH  		= 3,
} GuideType;		// Data Types

StatusType Array_Create();
StatusType Array_Print();
StatusType Array_Insert(uint32_t Data);
StatusType Array_Delete(uint8_t index);
StatusType Array_AscenSort();
StatusType Array_DescenSort();
StatusType Array_Search(uint32_t x);
StatusType Array_Quit();
StatusType Array_Choose();

