#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char name[20];
	cout << "�̸� : ";
	cin.getline(name, sizeof(name), '\n');
	cout << "�� ������ ���� : ";
	int score[3];
	int total_score = 0;
	for (int i = 0; i < 3; i++) {
		cin >> score[i];
		total_score += score[i];
	}
	char blank[11] = "          ";
	char line[61] = "============================================================";
	cout << blank << blank << "=====< ����ǥ >=====" << blank << blank<<'\n';
	cout << line << '\n';
	cout << setw(10) << "�̸�" << setw(10) << "����" << setw(10) << "����" << setw(10);
	// setw()�� �ʵ��� ����
	cout << "����" << setw(10) << "����" << setw(10) << "���" << '\n';
	cout << line << '\n';
	cout << setw(10) << name << setw(10) << score[0] << setw(10) << score[1] << setw(10);
	cout << score[2] << setw(10) << total_score << setw(10);
	cout << fixed << setprecision(2) << (double)total_score / 3.0 << '\n';
	// fixed�� ���� ���·� ������� ����
	// setprecision()���� ��Ÿ�� ��ȿ ���� 6(�⺻)���� 2�� ����
}