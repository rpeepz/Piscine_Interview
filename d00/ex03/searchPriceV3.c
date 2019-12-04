#include "header.h"

/*
**  djb2 by Dan Bernstein
*/
size_t              hash(char *input)
{
    size_t  hash_value = 5381;
    int     c;

    while ((c = *input++))
        hash_value = ((hash_value << 5) + hash_value) + c;
    /* hash * 33 + c */
    return (hash_value);
}

/*
**  allocate for capacity and set all elements to NULL
*/
struct s_dict       *dictInit(int capacity)
{
    struct s_dict   *dict = malloc(sizeof(struct s_dict));
    dict->items = malloc(sizeof(struct s_item *) * (capacity + 1));
    for (int i = 0; i < capacity + 1; i++) {
        dict->items[i] = NULL;
    }
    dict->capacity = capacity;
    return (dict);
}

/*
**  dict index based on hash % cpacity
**  inset value at index, if index is occupied,
**  inset at next pointer in list.
*/
int                 dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{

    struct s_item   *item;
    struct s_item   *tmp;

    int i = hash(key) % dict->capacity;
    if (!(item = malloc(sizeof(struct s_item))))
        return (0);
    item->key = key;
    item->value = value;
    item->next = NULL;
    if (dict->items[i]) {
        tmp = dict->items[i];
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = item;
    }
    else
        dict->items[i] = item;
    return (1);
}

/*
**  search at given hash index, checking collisions
*/
struct s_art        *dictSearch(struct s_dict *dict, char *key)
{
    int i = hash(key) % dict->capacity;
    while (dict->items[i])
    {
        if (!strcmp(dict->items[i]->key, key))
            return (dict->items[i]->value);
        dict->items[i] = dict->items[i]->next;
    }
    return (NULL);
}

int                 searchPrice(struct s_dict *dict, char *name)
{
    struct s_art *art = dictSearch(dict, name);
    return (art ? art->price : -1);
}
