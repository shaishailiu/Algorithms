#pragma once
#include "MergeSort.h"
#include "SortUtils.h"
#include <algorithm>

int merge(int* src,int* target,int start,int mid,int end)
{
    int left = start;
    int right = mid;
    for (int i = start; i < end; i++)
    {
        if (left < mid &&(right >= end || src[left] <= src[right]))
        {
            target[i] = src[left];
            left++;
        }
        else
        {
            target[i] = src[right];
            right++;
        }
    }
    return end - start;
}
int MergeSort::sort(int* ary, int length)
{
    int* src = ary;
    int* target = new int[length];
    memcpy(target, src, length * sizeof(int));

    int on = 0;
    bool flag = true;
    for (int width = 1; width < length; width *= 2)
    {
        for (int i = 0; i < length; i += width*2)
        {
            if (flag)
                on += merge(src, target, i, std::min(i + width, length), std::min(i + width * 2, length));
            else
                on += merge(target, src, i, std::min(i + width, length), std::min(i + width * 2, length));
            
        }
        flag = !flag;
    }
    if (flag)
    {
        ary = target;
    }
    return on;
}

std::string MergeSort::name()
{
    return "MergeSort";
}
