#include "IO.h"
#include <stdio.h>

// function for users to enter equipment information
void InputDevice(char name[], int* power, float* price) {
    printf("Insert Name Device: ");
    scanf("%s", name);
    printf("Insert Power (W): ");
    scanf("%d", power);
    printf("Insert Price: ");
    scanf("%f", price);
}
