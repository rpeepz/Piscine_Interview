#include "header.h"

char *rightShift(char *bin, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = 5; j > 0; j--)
			bin[j] = bin[j - 1];
    return (bin);
}
char *leftShift(char *bin, int k)
{
    char shift, swp;
    for (int j = 0; j < k; j++) {
        shift = '0';
        for (int i = 5 - j; i >= 0; i--) {
            swp = bin[i];
            bin[i] = shift;
            shift = swp;
        }
    }
    return (bin);
}

int toInt(char *bits)
{
    int res = 0;
    //count up each bit and apply corresponding bit to result
    for (int i = 0; bits[i]; i++)
        res |= (bits[i] & 1) << (6 - i - 1);
    return (bits[0] & 1 ? res-64 : res);
}
