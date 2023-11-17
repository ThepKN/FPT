#include <stdio.h>
#include "IO.h"
#include <stdint.h>
#include "List.h"



void main()
{
    StatusType status;
    char Inputchar, InputNam;
    float InputPower, InputPrice;
    uint8_t InputPosition;

    printf("Enter 'A' to add  a new device\n");
    printf("Enter 'D' to delete a device\n");
    printf("Enter 'P' to Print a device\n");
    printf("Enter 'E' to exit the program\n");
    do
    {
        printf("Choose an action: \n");
        fflush(stdin);
        scanf("%c", &Inputchar);
    }

    switch(Inputchar)
    {
        case LIST_ADD_NODE:
            break;
        case

    }

	(*List_FuncPtr[LIST_ADD_NODE])(10);		// HEAD = &Node1
	(*List_FuncPtr[LIST_ADD_NODE])(20);		// HEAD = &Node2
	(*List_FuncPtr[LIST_ADD_NODE])(30);		// HEAD = &Node3
	(*List_FuncPtr[LIST_ADD_NODE])(40);		// HEAD = &Node4

	//(*List_FuncPtr[LIST_DELETE_NODE])(3);

	(*List_FuncPtr[LIST_PRINT])(0);




//	StatusType status;
//	char Inputchar;
//
//	scanf("%d", &num);
//
//	do
//	{
//		// 1. User Input from Keyboard
//		scanf("%c", &Inputchar);
//
//		scanf("");	// IO_UserInput()
//
//		// 2. Call Array Management Function
//		switch(Inputchar)
//		{
//			switch (channel)
//			{
//				case 'i':
//					status = Array_Insert(userinput);
//					break;
//				case 'd':
//					status = Array_Delete(userinput);
//					break;
//				case 'c':
//					status = Array_Create(userinput);
//					break;
//				case 's':
//					status = Array_Sort(userinput);
//					break;
//				case 'x':
//
//				case 't':
//
//				case 'e':
//

}

