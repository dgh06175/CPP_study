#include <iostream>
using namespace std;

int my_strlen(const char* str, char ch = '\n')
{
	int count = 0; // ���ڿ��� ���̸� �� �����̴�.
	for (int i = 0; i < 100; i++) { // ���ڿ��� ��ü ���̸�ŭ �ݺ�
		if ((str[i] == ch) || (str[i] == 0))break;// ch�� ������ ���ڰ� �߰ߵǰų�, ���ڿ��� ������ break�ؼ� �� �̻� ���� �ʴ´�.
		count += 1;
	}
	return count;
}

int main()
{
	char str[100] = { 0, };
	char ch;
	int len;
	cout << "���ڿ� �Է� : ";
	cin >> str;
	len = my_strlen(str);
	cout << "���ڿ��� ���� : " << len << endl;

	cout << "���� �Է� : ";
	cin >> ch;
	len = my_strlen(str, ch);
	cout << ch << " ���������� ���� : " << len << endl;
}