#include "header.h"

/*
**  get length of array
**  call qsort with string compare to names of array elem
*/

int     cmp(const void *a, const void *b)
{
    return (strcmp((*(struct s_art **)a)->name, (*(struct s_art **)b)->name));
}

void    sortArts(struct s_art **arts)
{
    int     size = 0;
    while (arts && arts[size])
        ++size;
    qsort((void *)arts, size, sizeof(*arts), cmp);
}
