#include "MyString.h"
using namespace std;

int main()
{
	MyString ary[5];
	MyString res;
	int i;
	cout << "5���� �����̸� �Է�: ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];
	}
	cout << "ù��°�� �ι�°�� �� ���� �̸� : ";
	if (ary[0] > ary[1]) {
		cout << ary[0] << endl;
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	cout << "��� ���ڿ� ���:" << res << endl;
	cout << "�迭���� ���ڿ� ���..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}