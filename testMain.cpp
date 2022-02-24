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
	cout << "세 학생의 키 입력 : ";
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
			cout << "배열 읽기 실패" << endl;
		}
	}
	cout << "평균키 : " << tot / 3.0 << endl;
	return 0;
}