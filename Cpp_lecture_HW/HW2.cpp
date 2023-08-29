#include <iostream>
#include <string>
using namespace std;

/*
* 함수 오버로딩 문제
* 같은 이름이지만 매개변수에 따라
* 다르게 작동하는 함수들을 만들어야함
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


// main함수는 문제에서 주어짐
int main()
{
	double da, db;
	char str[20], chr[20];
	double dmax;
	const char* res;

	cout << "두 실수 입력 : ";
	cin >> da >> db;
	dmax = max(da, db);
	cout << "큰 값 : " << dmax << endl;

	cout << "두 문자열 입력 : ";
	cin >> str >> chr;
	res = max(str, chr);
	cout << "긴 문자열 : " << res << endl;
}