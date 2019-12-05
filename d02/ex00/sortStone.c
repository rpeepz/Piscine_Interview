#include "header.h"

void insert(struct s_stone **a, struct s_stone *b)
{
    struct s_stone *cur;
    /* Special case for the head end */
	if (!(*a) || (*a)->size >= b->size)
    {
        b->next = *a;
        *a = b;
    }
    else
    {
        /* Locate the node before the point of insertion */
        cur = *a;
        while (cur->next && cur->next->size < b->size)
            cur = cur->next;
        b->next = cur->next;
        cur->next = b;
    }
}

void sortStones(struct s_stone **stone)
{
    struct s_stone *s = NULL;

	struct s_stone *cur = *stone;
	while (cur) {
        // Store next for next iteration
	    struct s_stone *next = cur->next;

        // insert current in sorted linked list
		insert(&s, cur);

        // Update current
		cur = next;
	}
	*stone = s;
}

/*
** https://www.geeksforgeeks.org/insertion-sort-for-singly-linked-list/
*/