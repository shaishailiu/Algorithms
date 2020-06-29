#pragma once
#include "Sort.h"
class HeapSort : public  Sort
{
public:
	int sort(int* ary,int length);
    std::string name();
};