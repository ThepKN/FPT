#include <stdint.h
#include <stdlib.h>
#include <stdio.h>

#ifndef DEVICE_H
#define DEVICE_H

//Maximum number of equipment
#define MAX_DEVICES 10


typedef struct {
    char Name[100];
    float Power;
    float Price;
    struct Node *link;
}NodeType;


void Add_Device(NodeType **HEAD, int *deviceCount, char *Name, float *Power, float *Price);
void Delete_Device(NodeType **HEAD, int *deviceCount, int index);
void Display_Device(NodeType *HEAD, int deviceCount);

#endif // DEVICE_H
