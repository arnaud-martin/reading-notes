#define MAX_SIZE 1

typedef struct
{
    char elements[MAX_SIZE];
    int size;
} ArrayImplList;

void initializeList(ArrayImplList *list);
void insert(char element, int position, ArrayImplList *list);