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

void insertionSort(struct s_player **players)
{
    int     len = -1, i, j;
    while (players[++len])
        ;
    i = -1;
    //set base point
    while (++i < len)
        // iterate from base + 1 - len swapping when necessary
        for (j = i + 1; j < len; j++)
            if (players[i]->score < players[j]->score)
                swap_values(players[i], players[j]);
}
/*
**  https://www.geeksforgeeks.org/insertion-sort/
*/