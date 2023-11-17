#include <stdio.h>
#include "IO.h"
#include <stdint.h>
#include "List.h"

uint32_t sum(uint32_t a, uint32_t b)
{
	return a+b;
}

uint32_t sub(uint32_t a, uint32_t b)
{
	return a-b;
}

uint32_t mul(uint32_t a, uint32_t b)
{
	return a*b;
}
// Create a Function Pointer
// funcPtr = &sum -> call sum() via funcPtr

ListStatusType User_Function(uint32_t inputData)
{
	printf("User\n");
}

// BIOS (Boot)
void main()
{
	// Device Management (ID, Name, Power, Price)
	// Student Management  (Account, Name, Birth, ...)
	
//	printf("%d %d ", &main, &List_AddNode);

	//uint32_t sum(uint32_, uint32_t);	// Declare Function
	//uint32_t *funcPtr(uint32_t, uint32_t);		-> Function, return an address
//	uint32_t (*funcPtr)(uint32_t, uint32_t);	// Pointer = &Function
	
//	uint32_t a = 5;
//	uint32_t b = 4;
//	uint32_t result;
//	uint8_t userinput;
//	
////	uint32_t (*sumPtr)(uint32_t, uint32_t) = &sum;
////	uint32_t (*subPtr)(uint32_t, uint32_t) = &sub;
////	uint32_t (*mulPtr)(uint32_t, uint32_t) = &mul;
//	
//	uint32_t (*funcPtr[])(uint32_t, uint32_t) = {
//		['+'] = &sum,
//		['-'] = &sub,
//		['*'] = &mul
//	};
//
//	scanf("%c", &userinput);
//	// Check Userinput
//	if (funcPtr[userinput] != NULL)
//	{
//		result = (*funcPtr[userinput])(a,b);
//		printf("%d ", result);
//	}
//	
//	List_Print(0);
	
	
//	switch (userinput)
//	{
//		case '+':
//			result = (*funcPtr['+'])(a,b);
//			break;
//		case '-':
//			result = (*funcPtr['-'])(a,b);
//			break;
//		case '*':
//			result = (*funcPtr['*'])(a,b);
//			break;
//	}
	
	
//	&function => Call Function
	
//	List_Create(sizeof(StudentType));
//
	
	(*List_FuncPtr[LIST_ADD_NODE])(10);		// HEAD = &Node1
	(*List_FuncPtr[LIST_ADD_NODE])(20);		// HEAD = &Node2
	(*List_FuncPtr[LIST_ADD_NODE])(30);		// HEAD = &Node3
	(*List_FuncPtr[LIST_ADD_NODE])(40);		// HEAD = &Node4
	
	(*List_FuncPtr[LIST_DELETE_NODE])(3);
	
	(*List_FuncPtr[LIST_PRINT])(0);
	
	//printf("%d %d %d %d", HEAD->pNext->pNext->pNext->Data, HEAD->pNext->pNext->Data, HEAD->pNext->Data, HEAD->Data);
	
	
	
//	NodeType * ptr;
//	
//	// AddNode
//	// 1. Allocate Memory for Node
//	ptr = (NodeType*)malloc(sizeof(NodeType));
//	
//	// 2. Assign Value for Data
//	ptr->Data = 10;
//	
//	// 3. pNext = NULL
//	ptr->pNext = HEAD;
//	
//	// 4. HEAD -> Node1
//	HEAD = ptr;
//	
//	// AddNode2
//	// 1. Allocate Memory for Node
//	ptr = (NodeType*)malloc(sizeof(NodeType));
//	
//	// 2. Assign Value for Data
//	ptr->Data = 20;
//	
//	// 3. pNext = &Node1 = HEAD
//	ptr->pNext = HEAD;
//	
//	// 4. HEAD = &NewNode
//	HEAD = ptr;
//	
//	printf("%d", HEAD->Data);
	
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
//		}
//		
//		// Common
//		pointer[4] = {&Array_Insert, &Array_Delete, &Array_Create, &Array_Sort};
//		status = Array_Function[Inputchar](userinput);
////		
//	pointer[0] -> Call Array_Insert
//	pointer[1] -> Call Array_Delete
//	pointer[2] -> Call Array_Create
//	pointer[3] -> Call Array_Sort
//		// 3. Display Message Status
//		printf("%s", IO_Message(status));
//	} while (Inputchar != 'e');
}

