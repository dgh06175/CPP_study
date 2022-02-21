#include "MyAry.h"
#include "SmartArray.h"
#include <iomanip>
#include <iostream>
using namespace std;
char intToChar[10][10] = {
"��","��","��","��","�ټ�","����","�ϰ�","����","��ȩ","��"
};

int getMaxAndInput(const char* name, int num_of_subject)
{
	SmartArray score(num_of_subject);
	int i; // index
	bool res; // ��½� ����, ���а� ������ ����
	int num; // ������ �޾ƿ� ����
	int tot = 0; // ������ ���� ������ ����
	int temp; // ������ �Է¹����� ����� ����

	cout << name << "�� " << intToChar[num_of_subject - 1] << " ������ ���� �Է� : ";
	for (i = 0; i < num_of_subject; i++) {
		cin >> temp;
		if (score.put(i, temp) == false) {
			cout << "�迭 ���� ����" << endl;
		}
	}

	for (i = 0; i < num_of_subject; i++) {
		res = score.get(i, num);
		if (res)
		{
			tot += num; // i���� ������ tot�� ������
		}
		else
		{
			cout << "�迭 �б� ����" << endl;
		}
	}

	cout << name << "�� ���� : " << tot << endl;
	cout << name << "�� ��� : " << tot / (double)num_of_subject << endl;
	return score.getMax();
}

int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	
	const char* names[2] = { "ö��","����" }; // �̸� �̸� ����
	int num_of_subjects[2] = { 3, 5 }; // ���� ���� �̸� ����

	int max[2] = { getMaxAndInput(names[0], num_of_subjects[0]),getMaxAndInput(names[1], num_of_subjects[1]) };
	// max�迭�� ������ �ְ����� �����Ѵ�.

	if (max[0] > max[1]) {
		cout << names[0] << "�� �ְ����� " << names[1] << "���� ũ��..." << endl;
	}
	else {
		cout << names[0] << "�� �ְ����� " << names[1] << "���� ũ�� �ʴ�..." << endl;
	}

	return 0;
}