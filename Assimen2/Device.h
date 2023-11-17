#ifndef DEVICE_H
#define DEVICE_H

// Information storage structure of a device
typedef struct Device {
    char name[100];
    int power;
    float price;
    struct Device* next;
} Device;

// Add new equipment to the list
Device* AddDevice(Device* head, char name[], int power, float price);

// The device removes the device from the list
Device* DeleteDevice(Device* head, char name[]);

// The function shows the entire device
void DisplayDevices(Device* head);

#endif
