#include "Device.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Add new equipment to the list
Device* AddDevice(Device* head, char name[], int power, float price) {
    Device* newDevice = (Device*)malloc(sizeof(Device));
    strcpy(newDevice->name, name);
    newDevice->power = power;
    newDevice->price = price;
    newDevice->next = head;
    return newDevice;
}

// The device removes the device from the list
Device* DeleteDevice(Device* head, char name[]) {
    if (head == NULL) {
        printf("Drum list.\n");
        return head;
    }

    Device* current = head;
    Device* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }

        prev = current;
        current = current->next;
    }

    printf("No device has been found: %s\n", name);
    return head;
}

// The function shows the entire device
void DisplayDevices(Device* head) {
    if (head == NULL) {
        printf("Drum list.\n");
        return;
    }

    Device* current = head;

    printf("List of devices:\n");
    while (current != NULL) {
        printf("Name: %s, Power: %dW, Price: %.2f\n", current->name, current->power, current->price);
        current = current->next;
    }
}
