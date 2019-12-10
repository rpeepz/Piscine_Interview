#include "header.h"

char *getSum(char *a, char *b)
{
    char s, carry = 0;
    //count down each char
    for (int i = 5; i >= 0; i--) {
        //calculate result of current bit
		s = (a[i] & 1) + (b[i] & 0x1) + carry;
        //assign carry for next op
		carry = s >= 2 ? 1 : 0;
        //assign result
		a[i] = (s % 2) | 0x30;
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