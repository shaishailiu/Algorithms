#pragma once
#include "ShellSort.h"
#include "SortUtils.h"

int ShellSort::sort(int* ary, int length)
{
    int on = 0;
    for (int gap = length; gap = gap / 2;)
    {
        for (int i = gap; i < length; i++)
        {
            int minVal = ary[i];
            int j;
            for (j = i - gap; j >= 0; j-= gap)
            {
                on++;
                if (ary[j] > minVal)
                    ary[j + gap] = ary[j];
                else
                    break;
            }
            ary[j + gap] = minVal;
        }
    }
    return on;
}

std::string ShellSort::name()
{
    return "ShellSort";
}
