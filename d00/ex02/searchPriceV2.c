#include "header.h"

/*
**  set low and high index as 0 and length
**  compare array elem to search term at mid point of `l` and `h`
**  return for null pointer or end of array or if `l` and `h` cross
*/

int         binary_search(struct s_art **arts, int l, int h, int max, char *name)
{
    int mid = (l + h) / 2;
    if (h < l || mid == max)
        return (-1);
    int c = strcmp((arts[mid])->name, name);
    if (c > 0)
        return (binary_search(arts, l, mid - 1, max, name));
    if (c < 0)
        return (binary_search(arts, mid + 1, h, max, name));
    return (mid);
}

int         searchPrice(struct s_art **arts, int n, char *name)
{
    if (!arts || !*arts)
        return (-1);
    int low = 0;
    int high = n - 1;
    // recurrssive search
    return (binary_search(arts, low, high, n, name));
}
