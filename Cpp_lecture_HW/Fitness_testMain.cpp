#include <iostream>
#include "Fitness.h"
#include <iomanip>
using namespace std;

void MyFlush() {
	cin.clear();
	while (cin.get() != '\n');
}

// �޴��� ����ϰ� ����ڰ� ������ �޴��� ��ȣ�� �����ϴ� �Լ�
int PrintMenu(void)
{
	int menu;
	cout << "======================================================\n";
	cout << "1. ȸ�����\n2. ȸ����ü����\n3. ȸ�������˻�\n4. ȸ��Ż��\n5. Ư������ȸ��\n6. ����" << endl;
	cout << "======================================================\n";
	cout << "������ �޴��� ��ȣ�� �����ϼ��� : ";
	cin >> menu; // ������ �Է¹ޱ�
	while (cin.fail() || menu < 1 || menu > 6) { // ���ڰ� ���ų�, ������ �޾��� ��� ���Է� �䱸
		MyFlush();
		cout << "�߸��� ��ȣ�Դϴ�. ��ȣ�� �ٽ� �Է��ϼ��� : ";
		cin >> menu;
	}
	return menu;
}

// ȸ�� ��� �Լ�
Fitness* Menu_1(int memberCnt)
{
	char name[20];
	double weight;
	double height;
	cout << "\nȸ�� ����� �����մϴ�.\nȸ���� �̸��� �Է��ϼ��� : ";
	cin >> name;
	cout << "ȸ���� �����Ը� �Է��ϼ��� : ";
	cin >> weight;
	cout << "ȸ���� Ű�� �Է��ϼ��� : ";
	cin >> height;
	cout << endl;
	Fitness* member_info = new Fitness(memberCnt + 1, name, weight, height);
	return member_info;
}

// ȸ������ ��� �Լ�
void Menu_2(Fitness* fAry[100], int memberCnt)
{
	cout << '\n' << setw(4) << "��ȣ" << setw(12) << "�̸�" << setw(12) << "������(kg)" << setw(12) << "Ű(cm)" << endl;
	for (int i = 0; i < memberCnt; i++) {
		cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
		cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
	}
	cout << '\n';
}

// ȸ������ �˻� �Լ� (�������� ����)
void Menu_3(Fitness* fAry[100], int memberCnt)
{
	char name[20];
	cout << "�˻��� ȸ���� �̸��� �Է��ϼ��� : ";
	cin >> name;

	bool isExist = false;
	for (int i = 0; i < memberCnt; i++) {
		if (strcmp(fAry[i]->getName(), name) == 0) {
			isExist = true;
			break;
		}
	}

	if (isExist) {
		cout << "\n\n" << setw(4) << "��ȣ" << setw(12) << "�̸�" << setw(12) << "������(kg)" << setw(12) << "Ű(cm)" << endl;
		for (int i = 0; i < memberCnt; i++) {
			if (strcmp(fAry[i]->getName(), name) == 0) {
				cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
				cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
			}
		}
	}
	else {
		cout << '\n' << name << " ���� ������ �����ϴ�.";
	}
	cout << "\n\n";
}

// ȸ������ ���� �Լ�
int Menu_4(Fitness* fAry[100], int memberCnt) {
	char name[20];
	cout << "Ż���� ȸ���� �̸��� �Է��ϼ��� : ";
	cin >> name;

	int member_index = -1;
	for (int i = 0; i < memberCnt; i++) {
		if (strcmp(fAry[i]->getName(), name) == 0) {
			member_index = i;
			break;
		}
	}

	if (member_index == -1) {
		cout << '\n' << name << " ���� ������ �����ϴ�.";
		return memberCnt;
	}
	else {
		for (int i = member_index; i < memberCnt - 1; i++) {
			fAry[i]->setHeight(fAry[i + 1]->getHeight());
			fAry[i]->setWeight(fAry[i + 1]->getWeight());
			fAry[i]->setName(fAry[i + 1]->getName());
			fAry[i]->setHeight(fAry[i + 1]->getHeight());
			fAry[i]->setNum(fAry[i + 1]->getNum());
		}
		cout << name << "ȸ���� ������ �����Ǿ����ϴ�.\n";
		return memberCnt - 1;
	}
}

// Ư������ȸ�� ��� �Լ�
void Menu_5(Fitness* fAry[100], int memberCnt)
{
	bool isExist = false;
	for (int i = 0; i < memberCnt; i++) {
		if (fAry[i]->bmi() > 25.0) {
			isExist = true;
			break;
		}
	}

	if (isExist) {
		cout << "bmi�� 25 �̻��� Ư�� ���� ȸ������ ������ ����մϴ�.\n";
		cout << "\n" << setw(4) << "��ȣ" << setw(12) << "�̸�" << setw(12) << "������(kg)" << setw(12) << "Ű(cm)" << endl;
		for (int i = 0; i < memberCnt; i++) {
			if (fAry[i]->bmi() > 25.0) {
				cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
				cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
			}
		}
	}
	else {
		cout << "Ư�� ���� ����� ȸ���� �����ϴ�.";
	}
	cout << '\n';
}

int main()
{
	Fitness* fAry[100];
	int memberCnt = 0;
	int menu = PrintMenu();
	while (menu != 6) {
		switch (menu)
		{
		case 1: // 1. ȸ�����
		{
			Fitness* a = new Fitness;
			a = Menu_1(memberCnt);
			fAry[memberCnt++] = a;
			break;
		}
		case 2: // 2. ȸ����ü����
		{
			Menu_2(fAry, memberCnt);
			break;
		}
		case 3: // 3. ȸ�������˻�
		{
			Menu_3(fAry, memberCnt);
			break;
		}
		case 4: // 4. ȸ��Ż��
		{
			memberCnt = Menu_4(fAry, memberCnt);
			break;
		}
		case 5: // 5. Ư������ȸ��
		{
			Menu_5(fAry, memberCnt);
			break;
		}
		default:
			break;
		}
		menu = PrintMenu();
	}

	for (int i = 0; i < memberCnt; i++) {
		delete fAry[i];
	}
	cout << "�����Ϸ�";
	return 0;
}