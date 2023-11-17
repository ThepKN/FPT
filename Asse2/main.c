#include <stdio.h>
#include "IO.h"
#include <stdint.h>
#include "Device.h"

typedef struct Device
{
	uint8_t Name[20];
	uint32_t Power;
	uint32_t Price;
} DeviceType;

void printDevice(const void *data) 
{
    const DeviceType *device = (const DeviceType *)data;
    printf("Name: %s, Power: %dW, Price: %d$\n", device->Name, device->Power, device->Price);
}

void main()
{
	// Device Management (ID, Name, Power, Price)
	// Student Management  (Account, Name, Birth, ...)
	DeviceType device;
	uint32_t pos;	//positon want to delete
	uint8_t * ptr = (uint8_t *)&device;
	ListStatusType status;
	char inputChar;
	
//	Menu
	printf("-----DEVICE MANAGEMENT PROGRAM-----\n\n");
	printf("Please choose the following functions:\n");
	printf("'c' - Create Device list\n");
	printf("'a' - Add device to list\n");
	printf("'d' - Delete device from list\n");
	printf("'p' - Print list\n");
	printf("'e' - Quit Program\n\n");
	do
	{
		// 1. User Input from Keyboard
		fflush(stdin);
		scanf("%c", &inputChar);
		
		// 2. Call linked list Function
		switch(inputChar)
		{
			case 'c':
				status = List_CreateNode(sizeof(DeviceType));
				break;
			case 'a':
				printf("Enter Device Name: ");
				scanf("%s", device.Name);
				printf("Enter Device Power: ");
				scanf("%u", &device.Power);
				printf("Enter Device Price: ");
				scanf("%u", &device.Price);
				status = List_AddNode(ptr);
				break;
			case 'd':
				printf("Enter Device Position: ");
				scanf("%d", &pos);
				status = List_DeleteNode(pos);
				break;
			case 'p':
				status = printAllNodesReverse(printDevice);// printf from the last of node
			//	status = printAllNodes(printDevice); printf from the first node
				break;
			case 'e':
				status = List_Quit();
				break;
			default:
				status = List_Choose();		
		}

		// 3. Display Message Status
		printf("%s", IO_Message(status));
		fflush(stdin);
	} while (inputChar != 'e');
}

