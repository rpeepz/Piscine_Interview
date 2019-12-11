#include "header.h"

char *getXor(char *a, char *b)
{
    for (int i = 0; a[i]; i++) {
        a[i] = a[i] ^ (b[i] & 1);
    }
    return (a);
}

int toInt(char *bits)
{
    int res = 0;
    //count up each bit and apply corresponding bit to result
    for (int i = 0; bits[i]; i++)
        res |= (bits[i] & 1) << (6 - i - 1);
    return (res);
}
