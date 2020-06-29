#include "SortUtils.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iterator>
#include "Sort.h"
#include "SelectSort.h"
#include "InsertSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "HeapSort.h"

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
        printf("sort is error !!!!\n");
    else
        printf("sort is good !!!!\n");
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
int* copyAry(int* src, int length)
{
    int* ary = new int[length];
    memcpy(ary, src, length * sizeof(int));
    return ary;
}

void appleySort(Sort& s, int* ary,int size)
{
    int* cary = copyAry(ary, size);
    clock_t startTime, endTime;
    startTime = clock();
    int on = s.sort(cary, size);
    endTime = clock();
    //show(cary, size);
    printf("%s 's O(n) is %d ,time is %d\n", s.name().c_str(), on, endTime - startTime);
    delete cary;
}

void sortRun()
{
    int size = 20;
    int* ary = getRandomAry(size);
    //show(ary, size);
    printf("--------sort-------- \n");
    SelectSort sel;
    InsertSort ins;
    ShellSort shell;
    QuickSort quick;
    MergeSort merge;
    HeapSort heap;
    appleySort(sel, ary, size);
    appleySort(ins, ary, size);
    appleySort(shell, ary, size);
    appleySort(quick, ary, size);
    appleySort(merge, ary, size);
    appleySort(heap, ary, size);
}
