#include <iostream>
using namespace std;
#include "MyArray.h"

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	MyArray<double> height(3);

	int i;
	bool res;
	double dnum;
	double tot = 0;
	double temp;
	cout << "�� �л��� Ű �Է� : ";
	for (i = 0; i < 3; i++) {
		cin >> temp;
		height.put(i, temp);
	}
	for (i = 0; i < 3; i++) {
		res = height.get(i, dnum);
		if (res)
		{
			tot += dnum;
		}
		else {
			cout << "�迭 �б� ����" << endl;
		}
	}
	cout << "���Ű : " << tot / 3.0 << endl;
	return 0;
}