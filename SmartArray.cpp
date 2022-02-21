#include "SmartArray.h"
#include <iostream>
using namespace std;

bool SmartArray::put(int index, int val)
{
	if (MyArray::put(index, val)) {
		if (max < val) {
			max = val;
		}
	return true;
	}
	else {
		return false;
	}
}

int SmartArray::getMax()
{
	return max;
}

bool SmartArray::operator>(const SmartArray& br)
{
	if (this->max > br.max) { return true; }
	else { return false; }
}