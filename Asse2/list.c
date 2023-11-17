
#include "list.h"
static NodeType * HEAD = NULL;


void Add_Device(NodeType **HEAD, int *deviceCount, char *Name, float *Power, float *Price);
{
    //Check memory
    if(*deviceCount == MAX_DEVICES)
        printf("Full memory ");

    //Initialize new equipment
    NodeType *ptr = (NodeType*)malloc(sizeof(NodeType));
    strcpy(ptr->Name, Name);
    ptr->Power = Power;
    ptr->Price = Price;

    //Add equipment to the list
    HEAD[*deviceCount] = de
}

void Delete_Device(NodeType **HEAD, int *deviceCount, int index);

void Display_Device(NodeType *HEAD, int deviceCount);
