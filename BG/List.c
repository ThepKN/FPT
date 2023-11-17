#include "List.h"

// Create Linked List
static NodeType * HEAD = NULL;
static uint32_t Len = 0;
static uint32_t sizeofData = 0;

// Internal Function Prototypes
static ListStatusType List_AddNode(uint32_t);
static ListStatusType List_Print(uint32_t);
static ListStatusType List_DeleteNode(uint32_t);

const ListStatusType (*List_FuncPtr[])(uint32_t) = {
	[LIST_ADD_NODE] 	= &List_AddNode,
	[LIST_DELETE_NODE] 	= &List_DeleteNode,
	[LIST_PRINT] 		= &List_Print,
};

// Operators (Create/AddNode/DeleteNode)
static ListStatusType List_AddNode(char Name, float Power, float Price)
{		// addrHEAD = &HEAD
	NodeType * ptr;
	ListStatusType status = LIST_OVER_MEMORY;

	// 1. Allocate Memory for Node
	ptr = (NodeType*)malloc(sizeof(NodeType));

	if (NULL != ptr)
	{
		// 2. Assign Value for Data
		ptr->Data = inputData;
		ptr->Name = Name;
		ptr->Power = Power;
		ptr->Price = Price

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

static ListStatusType List_Print()
{
	NodeType *head = HEAD;      //ban*

	while (head != NULL)
	{
		printf("%s %f %f ", head->Name, head->Power, head->Price);		// pass by value
		head = head->pNext;
	}
	return LIST_OK;
}

static ListStatusType List_DeleteNode(uint32_t index)
{
	ListStatusType status = LIST_OK;    //Biến tạm
	NodeType *prvNode = HEAD;
	NodeType *freePtr = HEAD;
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

