#include "Device.h"

// Create Linked List
static NodeType * HEAD = NULL;
static uint32_t Len = 0;
static uint32_t sizeofData = 0;
static uint32_t dataNumber = 1;


ListStatusType List_CreateNode(uint8_t dataSize)
{
	ListStatusType status = LIST_OK;
	
    sizeofData = dataSize;
    return status;
}




ListStatusType List_AddNode(uint8_t *data)
{		
	if (sizeofData == 0) 
	{
        return LIST_NOT_EXIST;
    }

	// addrHEAD = &HEAD
	NodeType * newNode;
	ListStatusType status = LIST_OVER_MEMORY;
	
	// 1. Allocate Memory for Node
	newNode = (NodeType*)malloc(sizeofData);
	
	if (newNode == NULL) 
	{
        return status;
    }
	
	// 2. Assign Value for Data
	newNode->pData = (uint8_t *)malloc(sizeofData);
	if (newNode->pData == NULL) 
	{
        free(newNode);
        return status;
    }
	
	if (Memory_Copy(newNode->pData, data, sizeofData) == 1)// 1: data error
	{
		status = LIST_DATA_ERROR;
		return status;	
	}	
	// 3. pNext = NULL
	newNode->pNext = HEAD;		// = HEAD
		
	// 4. HEAD -> Node1
	HEAD = newNode;
		
	// Update Len of List
	Len++;
	status = LIST_OK;
	
	return status;
}


ListStatusType List_DeleteNode(uint32_t index)
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
		freePtr = freePtr->pNext;			
		prvNode->pNext = freePtr->pNext;
		Len--;
		free(freePtr);
	}
	
	return status;
}


uint32_t List_GetLen(void)
{
	return Len;
}

uint8_t Memory_Copy(uint8_t * dest, uint8_t * src, uint32_t num) //copy byte to byte, num is sizeofData
{
	if (dest == NULL || src == NULL) {
        return 1;							//List_DATA_ERROR
    }
	
    uint8_t *char_dest = dest;
    uint8_t *char_src = src;

    for (uint32_t i = 0; i < num; i++) 
	{
        *char_dest = *char_src;
        char_dest++;
        char_src++;
    }

    return 0;
}


ListStatusType List_Choose()
{
	ListStatusType status = LIST_CHOOSE;		//choose the function again
	
	return status;
}

ListStatusType List_Quit()
{
	ListStatusType status = LIST_QUIT;		//quit program
	
	return status;
}


void printNode(const NodeType *node, void (*printData)(const void *)) //parameter is pointer to function, call function printDevice in main.c
{
    if (node == NULL) 
	{
        printf("List is empty\n");
    } 
	else 
	{
        printf("Data%d: ", dataNumber++);
        if (node->pData != NULL) 
		{
            printData(node->pData);
        } 
		else 
		{
            printf("List is empty\n");
        }
    }
}

ListStatusType printAllNodes(void (*printData)(const void *)) //parameter is pointer to function, call function printDevice in main.c
{
	NodeType * head = HEAD;
	ListStatusType status = LIST_OK;
	
    while (head != NULL) {
        printNode(head, printData);
        head = head->pNext;
    }
    dataNumber = 1;
    return status;
}

ListStatusType printAllNodesReverse(void (*printData)(const void *)) 
{
    NodeType *current = HEAD;
    NodeType *prev = NULL;
    NodeType *next;

    // reverse node
    while (current != NULL) 
	{
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }

    current = prev; // Set HEAD

    while (current != NULL) 
	{
        printNode(current, printData);
        current = current->pNext;
    }

    // reserve node to origin
    current = prev;
    prev = NULL;
    while (current != NULL) 
	{
        next = current->pNext;
        current->pNext = prev;
        prev = current;
        current = next;
    }
    HEAD = prev;
	dataNumber = 1;
    return LIST_OK;
}
