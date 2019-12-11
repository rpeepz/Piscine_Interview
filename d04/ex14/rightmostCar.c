#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
    if (!parkingRow)
        return (-1);
    int i = 0;
    while (!(parkingRow & 1)) {
        parkingRow >>= 1;
        i++;
    }
    return (i);
}