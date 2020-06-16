#pragma once
#include "SelectSort.h"
#include "SortUtils.h"

void SelectSort::sort(int* ary, int length)
{
    int selFlag = 0;
    for (int i = 0; i < length; i++)
    {
        int selIdx = i;
        for (int j = i; j < length; j++)
        {
            if (ary[selIdx] > ary[j])
                selIdx = j;
        }
        if (selIdx != i)
            exchange(ary, i, selIdx);
    }
}
