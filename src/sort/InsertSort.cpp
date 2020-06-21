#pragma once
#include "InsertSort.h"
#include "SortUtils.h"

int InsertSort::sort(int* ary, int length)
{
    int on = 0;
    for (int i = 1; i < length; i++)
    {
        int minVal = ary[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            on++;
            if (ary[j] > minVal)
                ary[j + 1] = ary[j];
            else
                break;
        }
        ary[j + 1] = minVal;
    }
    return on;
}

std::string InsertSort::name()
{
    return "InsertSort";
}
