#pragma once
#include "MyAry.h"
class SmartArray : public MyArray
{
private:
	int max;
public:
	SmartArray() { max = 0; }
	SmartArray(int s):MyArray(s), max(0)
	{}
	bool put(int index, int val);
	int getMax();
	bool operator>(const SmartArray& br);
};