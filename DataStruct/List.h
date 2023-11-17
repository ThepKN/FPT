#include <stdint.h>
#include <stdlib.h>

typedef struct Node
{
     uint8_t *pData;
     struct Node*pNext;
}NodeType;

typedef enum
{
	LIST_OK				= 0U,
	LIST_OUT_OF_RANGE 	= 1U,
	LIST_OVER_MEMORY    = 2U,

} ListStatusType;
