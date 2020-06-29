#pragma once
#include "HeapSort.h"
#include "SortUtils.h"

void heapIfy(int* ary, int length,int i, int& n) {
    n++;
    int max = i;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    if (c1 < length && ary[max] < ary[c1])
        max = c1;
    if (c2 < length && ary[max] < ary[c2])
        max = c2;
    if (max != i)
    {
        exchange(ary, max, i);
        heapIfy(ary, length, max,n);
    }
}
void buildHeapIfy(int* ary, int length,int& n) {
    for (int i = (length - 2) / 2; i >= 0; i--) {
        heapIfy(ary, length, i,n);
    }
}

int HeapSort::sort(int* ary, int length)
{
    int on = 0;
    buildHeapIfy(ary, length,on);
    for (int i = length-1; i >= 0; i--)
    {
        exchange(ary, 0, i);
        heapIfy(ary, i, 0,on);
    }
    return on;
}

std::string HeapSort::name()
{
    return "HeapSort";
}
