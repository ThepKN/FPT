#include "List.h"

// Create Linked List
static NodeType * HEAD = NULL;
static uint32_t Len = 0;
static uint32_t sizeofData = 0;

// Internal Function Prototypes
static ListStatusType List_AddNode(uint32_t);
static ListStatusType List_Print(uint32_t);
static ListStatusType List_DeleteNode(uint32_t);
static ListStatusType List_Find(uint32_t);
static ListStatusType List_Sort(uint32_t);

const ListStatusType (*List_FuncPtr[])(uint32_t) = {
	[LIST_ADD_NODE] 	= &List_AddNode,
	[LIST_DELETE_NODE] 	= &List_DeleteNode,
	[LIST_PRINT] 		= &List_Print,
};

// Operators (Create/AddNode/DeleteNode)
static ListStatusType List_AddNode(uint32_t inputData)
{		// addrHEAD = &HEAD
	NodeType * ptr;
	ListStatusType status = LIST_OVER_MEMORY;
	
	// 1. Allocate Memory for Node
	ptr = (NodeType*)malloc(sizeof(NodeType));
	
	if (NULL != ptr)
	{
		// 2. Assign Value for Data
		ptr->Data = inputData;
		
		// 3. pNext = NULL
		ptr->pNext = HEAD;		// = HEAD
		
		// 4. HEAD -> Node1
		HEAD = ptr;
		
		// Update Len of List
		Len++;
		status = LIST_OK;
	}
	
	return status;
}

static ListStatusType List_Print(void)
{
	// HEAD -> 40 -> 30 -> 20 -> 10 -> NULL
	NodeType * head = HEAD;
	
	while (head != NULL)
	{
		printf("%d ", head->Data);		// 40 
		head = head->pNext;
	}
	return LIST_OK;
}

static ListStatusType List_DeleteNode(uint32_t index)
{
	ListStatusType status = LIST_OK;
	NodeType * prvNode = HEAD;
	NodeType * freePtr = HEAD;
	uint8_t count;
	
	if (0U == index || index > Len)
	{
		status = LIST_OUT_OF_RANGE;
	}
	else if (1U == index)
	{
		HEAD = HEAD->pNext;
		Len--;
		free(freePtr);
	}
	else
	{
		for (count = 1U; count < index-1U; count++)
		{
			prvNode = prvNode->pNext;
			freePtr = freePtr->pNext;
		}
		freePtr = freePtr->pNext;		// Index	
		prvNode->pNext = freePtr->pNext;
		Len--;
		free(freePtr);
	}
	
	return status;
}

static ListStatusType List_Find(uint32_t Data)
{
	
}

static ListStatusType List_Sort(uint32_t Data)
{
	
}

uint32_t List_GetLen(void)
{
	return Len;
}
