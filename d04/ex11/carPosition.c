#include "header.h"

int carPosition(unsigned int parkingRow)
{
    if (!parkingRow || (parkingRow & 1 && parkingRow != 1))
        return (-1);
    int i;
    unsigned int cmp = 1;
    for (i = 0; i < 32; i++) {
        cmp = (1 << i);
        if (cmp == parkingRow)
            break ;
    }
    return (i);
}
