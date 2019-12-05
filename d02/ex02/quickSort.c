#include "header.h"

void swap_values(struct s_player *a, struct s_player *b)
{
    char    *tmp_name = b->name;
    int     tmp_score = b->score;
    b->name = a->name;
    b->score = a->score;
    a->name = tmp_name;
    a->score = tmp_score;
}

int  partition(struct s_player **players, int low, int high)
{
    struct s_player *pivot = players[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (players[j]->score > pivot->score) {
            i++;
            swap_values(players[i], players[j]);
        }
    }
    swap_values(players[i + 1], players[high]);
    return i + 1;
}

void quick(struct s_player **players, int low, int high)
{
    if (low < high)
    {
        int index = partition(players, low, high);
        quick(players, low, index - 1);
        quick(players, index + 1, high);
    }
}

void quickSort(struct s_player **players)
{
    int len = -1, low = 0;
    while (players[++len])
        ;
    quick(players, low, len - 1);
}
/*
**  https://www.geeksforgeeks.org/quick-sort/
*/
