#include <stdio.h>
#include <stdlib.h>
#include "sort/SortUtils.h"

int main(int argc, char *argv[])
{
    int size = 10;
    int* ary = getRandomAry(size);
    show(ary, size);
    return 0;
}
