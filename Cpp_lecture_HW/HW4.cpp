#include <iostream>
using namespace std;

int my_strlen(const char* str, char ch = '\n')
{
	int count = 0; // 문자열의 길이를 셀 변수이다.
	for (int i = 0; i < 100; i++) { // 문자열의 전체 길이만큼 반복
		if ((str[i] == ch) || (str[i] == 0))break;// ch와 동일한 문자가 발견되거나, 문자열이 끝나면 break해서 더 이상 세지 않는다.
		count += 1;
	}
	return count;
}

int main()
{
	char str[100] = { 0, };
	char ch;
	int len;
	cout << "문자열 입력 : ";
	cin >> str;
	len = my_strlen(str);
	cout << "문자열의 길이 : " << len << endl;

	cout << "문자 입력 : ";
	cin >> ch;
	len = my_strlen(str, ch);
	cout << ch << " 이전까지의 길이 : " << len << endl;
}