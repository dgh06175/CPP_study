#include <iostream>
using namespace std;

// ���ڿ��� ���ڸ� �ް� ���ڿ����� ���� ���������� ����ϴ� �Լ�
void str_prn(const char* str, char ch = '\n')
{
	for (int i = 0; i < 80; i++) {
		if (str[i] == ch)break; // �Է��� ���� �����̸� ����ϱ� ���� ����
		if (str[i] > 0) cout << str[i]; // �����Ⱚ�� �ƴ϶�� ���
	}
	cout << endl;
}

// main �Լ��� �������� �־���
int main()
{
	char str[80];
	cout << "���� �Է� : ";
	cin.getline(str, sizeof(str));
	char ch;
	cout << "���� �Է� : ";
	cin >> ch;
	str_prn(str);
	str_prn(str, ch);
	return 0;
}