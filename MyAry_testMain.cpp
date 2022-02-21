#include "MyAry.h"
#include "SmartArray.h"
#include <iomanip>
#include <iostream>
using namespace std;
char intToChar[10][10] = {
"한","두","세","네","다섯","여섯","일곱","여덟","아홉","열"
};

int getMaxAndInput(const char* name, int num_of_subject)
{
	SmartArray score(num_of_subject);
	int i; // index
	bool res; // 출력시 성공, 실패값 저장할 변수
	int num; // 점수를 받아올 변수
	int tot = 0; // 점수의 합을 저장할 변수
	int temp; // 점수를 입력받을때 사용할 변수

	cout << name << "의 " << intToChar[num_of_subject - 1] << " 과목의 점수 입력 : ";
	for (i = 0; i < num_of_subject; i++) {
		cin >> temp;
		if (score.put(i, temp) == false) {
			cout << "배열 쓰기 실패" << endl;
		}
	}

	for (i = 0; i < num_of_subject; i++) {
		res = score.get(i, num);
		if (res)
		{
			tot += num; // i번의 점수를 tot에 더해줌
		}
		else
		{
			cout << "배열 읽기 실패" << endl;
		}
	}

	cout << name << "의 총점 : " << tot << endl;
	cout << name << "의 평균 : " << tot / (double)num_of_subject << endl;
	return score.getMax();
}

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	
	const char* names[2] = { "철수","메텔" }; // 이름 미리 저장
	int num_of_subjects[2] = { 3, 5 }; // 과목 개수 미리 저장

	int max[2] = { getMaxAndInput(names[0], num_of_subjects[0]),getMaxAndInput(names[1], num_of_subjects[1]) };
	// max배열에 각각의 최고점을 저장한다.

	if (max[0] > max[1]) {
		cout << names[0] << "는 최고점은 " << names[1] << "보다 크다..." << endl;
	}
	else {
		cout << names[0] << "는 최고점은 " << names[1] << "보다 크지 않다..." << endl;
	}

	return 0;
}