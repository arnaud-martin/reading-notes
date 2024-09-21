#include <stdio.h>
#include "array.h"

// TODO: Add a comment explaining why I need to initialize the size but not elements.
void initializeList(ArrayImplList *list)
{
    list->size = 0;
}

// TODO: Implement:
// - moving elements rights when inserting at p
// - checking boundaries
void insert(char element, int position, ArrayImplList *list)
{
    list->elements[position] = element;
    list->size = list->size + 1;
}
