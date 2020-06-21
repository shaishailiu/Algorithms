#pragma once
#include <string>
class Sort
{
public:
	virtual int sort(int* ary,int length) = 0;
    virtual std::string name();
};
