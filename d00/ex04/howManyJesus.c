#include "header.h"

int     howManyJesus(char *bible, char *jesus)
{
    int count = 0;
    // naive method
    // for (int i = 0; bible[i]; i++) {
    //     if (!strncmp(&bible[i], jesus, strlen(jesus)))
    //         ++count;
    // }
    // return (count);

    int M = strlen(jesus);
    int N = strlen(bible);
    int i, p, t, h;
    int prime = 101, d = 256;
    i = 0;
    p = 0;
    t = 0;
    h = 1;

    for (i = 0; i < M-1; i++)
        h = (h * d) % prime;
    // calculate hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + jesus[i]) % prime;
        t = (d * t + bible[i]) % prime;
    }
    // move window over one by one
    for (i = 0; i <= N - M; i++)
    {
        //if hash value of window matches hash of pattern
        if (p == t)
            if (!strncmp(&bible[i], jesus, M))
                ++count;
        if (i < N - M)
        {
            // get hash of next window
            t = (d * (t - bible[i] * h) + bible[i + M]) % prime;
            if (t < 0)
                t += prime;
        }
    }
    return (count);
}