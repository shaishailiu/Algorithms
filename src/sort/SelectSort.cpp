#pragma once
#include "SelectSort.h"
#include "SortUtils.h"

int SelectSort::sort(int* ary, int length)
{
    int on = 0;
    for (int i = 0; i < length; i++)
    {
        int selIdx = i;
        for (int j = i; j < length; j++)
        {
            on++;
            if (ary[selIdx] > ary[j])
                selIdx = j;
        }
        if (selIdx != i)
            exchange(ary, i, selIdx);
    }
    return on;
}

std::string SelectSort::name()
{
    return "SelectSort";
}
