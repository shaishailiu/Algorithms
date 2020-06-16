#pragma once
#include "InsertSort.h"
#include "SortUtils.h"

void InsertSort::sort(int* ary, int length)
{
    for (int i = 1; i < length; i++)
    {
        int minVal = ary[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (ary[j] > minVal)
                ary[j + 1] = ary[j];
            else
                break;
        }
        ary[j + 1] = minVal;
    }
}
