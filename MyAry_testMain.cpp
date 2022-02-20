#include "MyAry.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	MyArray score(3);
	int i;
	bool res;
	int num;
	int tot = 0;
	int temp;

	for (i = 0; i < 4; i++) {
		cout << i + 1 << "번 학생의 성적 입력 : ";
		cin >> temp;
		if (score.put(i, temp) == false) {
			cout << "배열 쓰기 실패" << endl;
		}
	}
	for (i = 0; i < 4; i++) {
		res = score.get(i, num);
		if (res)
		{
			tot += num;
		}
		else
		{
			cout << "배열 읽기 실패" << endl;
		}
	}
	cout << "평균 :" << tot / 3.0 << endl;
	
	MyArray tempArray(score);
	MyArray tmp;
	tmp = score;

	return 0;
}