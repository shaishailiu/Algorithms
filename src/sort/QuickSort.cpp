#pragma once
#include "QuickSort.h"
#include "SortUtils.h"

void quickSort(int* ary,int L,int R,int& on)
{
    if (L >= R)
        return;
    int left = L;
    int right = R;
    int pivot = ary[left];
    while (left < right)
    {
        on++;
        while (left<right && ary[right] >= pivot)
            right--;
        if (left < right)
            ary[left] = ary[right];
        while (left < right && ary[left] <= pivot)
            left++;
        if (left < right)
            ary[right] = ary[left];
        
        if (left == right)
            ary[left] = pivot;
    }
    
    quickSort(ary, L, right - 1, on);
    quickSort(ary, right + 1, R, on);
}

int QuickSort::sort(int* ary, int length)
{
    int on = 0;
    quickSort(ary, 0, length - 1, on);
    return on;
}

std::string QuickSort::name()
{
    return "QuickSort";
}
