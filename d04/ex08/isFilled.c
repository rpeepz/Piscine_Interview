#include "header.h"

int isFilled(unsigned int parkingRow)
{
    while (parkingRow) {
        if (!(parkingRow & 1))
            return (0);
        parkingRow >>= 1;
    }
    return (1);
}