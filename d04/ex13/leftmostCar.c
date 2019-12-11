#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
    if (!parkingRow)
        return (-1);
    unsigned cmp = __UINT32_MAX__;
    int i;
    for (i = 0; cmp >= parkingRow; i++) {
        cmp >>= 1;
    }
    return (32 - i);
}
