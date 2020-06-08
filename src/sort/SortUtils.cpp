#include "SortUtils.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>

void exchange(int* ary, int i, int j)
{
    int temp = ary[j];
    ary[j] = ary[i];
    ary[i] = temp;
}

void show(int* ary, int length)
{
    bool error = false;
    for (int i = 0; i < length; i++)
    {
        printf("%d,", ary[i]);
        if (i > 0 && ary[i-1] > ary[i])
            error = true;
    }
    printf("\n");
    if (error)
        printf("sort is error !!!!");
    else
        printf("sort is good !!!!");
}

int* getRandomAry(int length)
{
    int max = length * 10;
    srand(time(0));
    int *ary = new int[length];
    for (int i = 0; i < length; i++)
    {
        ary[i] = rand() % max + 1;
    }
    return ary;
}
