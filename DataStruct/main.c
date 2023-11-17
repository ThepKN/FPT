#include <stdio.h>
#include <stdint.h>
#include "array.h"
#include "IO.h"
#include "List.h"

// orrganize data


// operators (create/adddNode/De;eteNode)
//add Node

typedef struct
{
    uint8_t ID;
    uint8_t Name[10];
    uint32_t Power;
    uint16_t Price;
}DeviceType;

typedef struct
{
    uint8_t Account;
    uint8_t Name[10];
    uint32_t Birth;
    uint16_t Price;
}StudentType;

int main()
{
    //NodeType * HEAD = NULL;

    List_AddNode(10);
    List_AddNode(20);
    List_AddNode(30);
    List_AddNode(40);


   printf("status = %d ",List_DeleteNode(3)) ;
    List_Print();
}
