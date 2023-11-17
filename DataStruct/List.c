#include "List.h"
// Create Linked list
static NodeType* HEAD = NULL;
static uint32_t Len =0;




ListStatusType List_AddNode(uint32_t inputData)
{   //addrHEAD = &HEAD

     NodeType* ptr;
     ListStatusType status = LIST_OVER_MEMORY;
     //1. Allocate memory for node
     ptr = (NodeType*)malloc(sizeof(NodeType));

     if(NULL != ptr)
     {
    //2.Assign Value for Data
     ptr->Data = inputData;

     //3.pNext = NULL
     ptr->pNext = HEAD;  // =HEAD

     //4.HEAD -> Node1
     HEAD = ptr;
     //update len
     Len++;
     status = LIST_OK;
     }
    return status;
}

void List_Print(void) {
    NodeType* head = HEAD;    //tạo bản sao head = HEAD(truyền tham trị)


    while (head != NULL) {
        printf("%d ", head->Data);
        head =head->pNext;
    }
}

ListStatusType List_DeleteNode(uint8_t index)
{
    //index =1
 /*   NodeType* freePTR = *addrHEAD;
    *addrHEAD = *addrHEAD->pNext;
    free(freePTR);*/
	ListStatusType status = LIST_OK;
    NodeType* prvNode = HEAD;
    NodeType* freePTR = HEAD;
    uint8_t counter;
    //index=1;

    if(0 == index || index > Len)
    {
        status = LIST_OUT_OF_RANGE;
    }
    else if(1 == index)
    {
        HEAD = HEAD->pNext;
        Len--;
        free(freePTR);
    }
    else
    {
       // printf("compare = %d\n", 1U < index-1);
        for(counter =1U; counter <index-1U; counter++)  //U la kieu ugsined
        {
            //printf("Count = %d\n", counter);
            prvNode = prvNode->pNext;
            freePTR = freePTR->pNext;
        }
        freePTR = freePTR->pNext;
        prvNode->pNext = freePTR->pNext;
    	Len--;
    	free(freePTR);
	}

	return status;
    }
uint32_t List_Getlen(void)
{
    return Len;
}
