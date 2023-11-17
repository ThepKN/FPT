#include <stdio.h>
#include "Device.h"
#include "IO.h"

int main() {
    Device* devices = NULL;
    char choice;
    char name[100];
    int power;
    float price;

    do {
        printf("Option (A: Add Device, D: Delete Device, P: Print Device, Q: Exit): ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
                InputDevice(name, &power, &price);
                devices = AddDevice(devices, name, power, price);
                break;
            case 'D':
                printf("add Device: ");
                scanf("%s", name);
                devices = DeleteDevice(devices, name);
                break;
            case 'P':
                DisplayDevices(devices);
                break;
            case 'Q':
                // Exit Program
                break;
            default:
                printf("Invalid selection .\n");
        }
    } while (choice != 'Q');

// Liberate memory at the end of the program
while (devices != NULL) {
        Device* next = devices->next;
        free(devices);
        devices = next;
    }

    return 0;
}
