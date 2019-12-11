#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
    for (int i = 0; i < n; i++) {
        parkingRow &= ~(1 << i);
    }
    return (parkingRow);
}
