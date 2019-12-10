#include "header.h"

char *getNot(char *s)
{
    for (int i = 0; s[i]; i++) {
        s[i] = s[i] == '1' ? '0' : '1';
    }
    return (s);
}

char *getAnd(char *a, char *b)
{
    if (*a == '~') {
        ++a;
        a = getNot(a);
    }
    if (*b == '~') {
        ++b;
        b = getNot(b);
    }
    for (int i = 0; a[i]; i++) {
        a[i] = ((a[i] & 1) & (b[i] & 1)) | 0x30;
    }
    return (a);
}

char *getOr(char *a, char *b)
{
    if (*a == '~') {
        ++a;
        a = getNot(a);
    }
    if (*b == '~') {
        ++b;
        b = getNot(b);
    }
    for (int i = 0; a[i]; i++) {
        a[i] = ((a[i] & 1) | (b[i] & 1)) | 0x30;
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
