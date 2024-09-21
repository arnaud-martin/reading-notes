#include <stdio.h>
#include "array.h"

int test_list_array_should_insert()
{
    ArrayImplList list;
    initializeList(&list);
    insert('A', 0, &list);

    char expected[] = {"A"};
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (list.elements[i] != expected[i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int error_count = 0;
    error_count += test_list_array_should_insert();

    printf(error_count == 0 ? "Succeeded" : "Failed");

    return error_count;
}