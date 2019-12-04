#include "header.h"

/*
**  compare array elem to search term
**  return for null pointer or end of array
*/

int     searchPrice(struct s_art **arts, char *name)
{
    // recurrssive search
    if (!arts || !*arts)
        return (-1);
    if (strcmp((*arts)->name, name))
        return (searchPrice(++(arts), name));
    return ((*arts)->price);

    // iterative search
    while (arts && *arts)
    {
        if (!strcmp((*arts)->name, name))
            return ((*arts)->price);
        ++(arts);
    }
    return (-1);
}
