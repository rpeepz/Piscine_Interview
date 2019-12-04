#include <stdlib.h>
#include <string.h>

struct      s_art
{
    char    *name;
    int     price;
};

void        sortArts(struct s_art **arts);
struct s_art **getArts(void);
