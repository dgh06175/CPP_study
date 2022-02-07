#include <iostream>
using namespace std;

// 문자열과 문자를 받고 문자열에서 문자 직전까지만 출력하는 함수
void str_prn(const char* str, char ch = '\n')
{
	for (int i = 0; i < 80; i++) {
		if (str[i] == ch)break; // 입력한 문자 차례이면 출력하기 전에 정지
		if (str[i] > 0) cout << str[i]; // 쓰레기값이 아니라면 출력
	}
	cout << endl;
}

// main 함수는 문제에서 주어짐
int main()
{
	char str[80];
	cout << "문장 입력 : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "문자 입력 : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);
	return 0;
}