#ifndef _DEVICE_H
#define _DEVICE_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>



typedef enum
{
	LIST_OK				= 0U,
	LIST_OUT_OF_RANGE 	= 1U,
	LIST_OVER_MEMORY	= 2U,
	LIST_CHOOSE			= 3U,
	LIST_QUIT			= 4U,
	LIST_NOT_EXIST		= 5U,
	LIST_DATA_ERROR		= 6U
} ListStatusType;		// Data Types

// Organize Data
typedef struct Node
{
	uint8_t * pData;
	struct Node * pNext;
} NodeType;


// Function Prototype
uint32_t List_GetLen(void);
ListStatusType List_AddNode(uint8_t *data);
ListStatusType List_DeleteNode(uint32_t index);
ListStatusType List_CreateNode(uint8_t dataSize);
uint8_t Memory_Copy(uint8_t * dest, uint8_t * src, uint32_t num);
ListStatusType List_Choose();
ListStatusType List_Quit();
void printNode(const NodeType *node, void (*printData)(const void *));
ListStatusType printAllNodes(void (*printData)(const void *));
ListStatusType printAllNodesReverse(void (*printData)(const void *));

#endif /* _DEVICE_H */