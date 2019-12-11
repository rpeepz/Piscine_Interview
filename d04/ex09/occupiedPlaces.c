#include "header.h"

/*
**  the number of times this solution loops is equal to
**  the number of set bits in a given integer.
*/

/* Using Brian Kernighan’s Algorithm */
int occupiedPlaces(unsigned int parkingRow)
{
    int set = 0;
    while (parkingRow && ++set)
        parkingRow &= (parkingRow - 1);
    return (set);
}