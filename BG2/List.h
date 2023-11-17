#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "Command.h"

typedef enum
{
	LIST_OK				= 0U,
	LIST_OUT_OF_RANGE 	= 1U,
	LIST_OVER_MEMORY	= 2U,
} ListStatusType;		// Data Types

// Organize Data
typedef struct Node
{
	uint32_t Data;
	struct Node * pNext;
} NodeType;

// Function Pointer to handle List
//	['A'] = List_AddNode,
//	['D'] = List_DeleteNode,
//	['P'] = List_Print,
//	['F'] = List_Find,
//	['S'] = List_Sort
extern const ListStatusType (*List_FuncPtr[])(uint32_t);

// Function Prototype
uint32_t List_GetLen(void);

