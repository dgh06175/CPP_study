#include <iostream>
#include <string>
using namespace std;

/*
* �Լ� �����ε� ����
* ���� �̸������� �Ű������� ����
* �ٸ��� �۵��ϴ� �Լ����� ��������
*/

double max(double da, double db)
{
	if (da > db) {
		return da;
	}
	else {
		return db;
	}
}


const char* max(char str[], char chr[])
{
	if (strlen(str) >= strlen(chr)) {
		return str;
	}
	else {
		return chr;
	}
}


// main�Լ��� �������� �־���
int main()
{
	double da, db;
	char str[20], chr[20];
	double dmax;
	const char* res;

	cout << "�� �Ǽ� �Է� : ";
	cin >> da >> db;
	dmax = max(da, db);
	cout << "ū �� : " << dmax << endl;

	cout << "�� ���ڿ� �Է� : ";
	cin >> str >> chr;
	res = max(str, chr);
	cout << "�� ���ڿ� : " << res << endl;
}