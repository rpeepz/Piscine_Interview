#include <stdlib.h>
#include <string.h>

struct      s_art
{
    char    *name;
    int     price;
};

int         searchPrice(struct s_art **arts, char *name);
struct s_art **getArts(void);