#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr); // first free

    // some code that uses ptr

    free(ptr); // second free
    return 0;
}
