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
int                 dictInsert(struct s_dict *dict, char *key, int value)
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
int             dictSearch(struct s_dict *dict, char *key)
{
    struct s_item   *item;

    int i = hash(key) % dict->capacity;
    if (!(item = dict->items[i]))
        return (-1);
    while (item)
    {
        if (!strcmp(item->key, key))
            return (item->value);
        item = item->next;
    }
    return (-1);
}

char *ft_strndup(char *s, int n)
{
    char *tmp = malloc(n + 1);
    tmp[n] = 0;
    for (int i = 0; i < n; i++) {
        tmp[i] = s[i];
    }
    return (tmp);
}

char *compress(char *book, struct s_dict *dict)
{
    int i, j, d, len;
    size_t h;
    char *tmp = NULL;
    char *compress = NULL;
    struct s_item *item;
    len = strlen(book);
    compress = malloc(len + 1);
    memset(compress, 0, len);
    i = 0;
    while (book[i]) {
        j = 0;
        while (!isspace(book[i + j])) //measure length of word
            ++j;
        if (j) {
            tmp = ft_strndup(&book[i], j);
            h = hash(tmp) % dict->capacity; //get hash of substring
            //see if substring appears in dictionary
            if ((d = dictSearch(dict, tmp)) > 0) {
                item = dict->items[h];
                while (item) {
                    if (item->value == d && !strcmp(tmp, item->key)) {
                        // printf("value %d - index %d\ntmp %s - key %s\n", item->value, d, tmp, item->key);
                        tmp = malloc(3);
                        tmp[0] = '@';
                        tmp[1] = d;
                        tmp[2] = 0;
                        break ;
                    }
                    item = item->next;
                }
            }
        }
        else
        {
            while (book[i + j] && isspace(book[i + j])) //measure length of whitespace
                ++j;
            tmp = ft_strndup(&book[i], j);
        }
        compress = strcat(compress, tmp);
        free(tmp);
        tmp = NULL;
        i+=j;
    }
    return (compress);
}