#include "MyString.h"
using namespace std;

int main()
{
	MyString ary[5];
	MyString res;
	int i;
	cout << "5개의 과일이름 입력: ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];
	}
	cout << "첫번째와 두번째중 긴 과일 이름 : ";
	if (ary[0] > ary[1]) {
		cout << ary[0] << endl;
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	cout << "모든 문자열 출력:" << res << endl;
	cout << "배열내의 문자열 출력..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}