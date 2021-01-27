/*
 * Banking System Ver 0.1
 * �ۼ��� : �̻���
 * �� �� : OOP �ܰ躰 ������Ʈ�� �⺻ Ʋ ����
 */

#include <iostream>
using namespace std;
const int NAME_LEN = 20;

int Menu(void);
void Make(void);
void Deposit(void);
void Withdraw(void);
void PrintAll(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, PRINTALL, EXIT };

typedef struct {
	int ID;
	char name[NAME_LEN];
	int money;
}Account;
Account info[100];
int n = 0;

int main(void)
{
	int choice;
	while (choice = Menu())
	{
		switch (choice) {
		case MAKE:
			Make();
			break;
		case DEPOSIT:
			Deposit();
			break;
		case WITHDRAW:
			Withdraw();
			break;
		case PRINTALL:
			PrintAll();
			break;
		case EXIT:
			return 0;
		default:
			cout << "���� �߻�" << endl;
		}
	}
	return 0;
}

int Menu(void)
{
	int select;
	cout << "----------Menu----------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
	cin >> select;
	cout << endl;
	return select;
}

void Make(void)
{
	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> info[n].ID;
	cout << "�̸�: "; cin >> info[n].name;
	cout << "�Աݾ�: "; cin >> info[n].money;
	cout << endl;
	n++;
}

void Deposit(void)
{
	int id, num = -1, i, money;
	cout << "[�Ա�]" << endl;
	cout << "����ID: ";
	cin >> id;
	for (i = 0; i < 100; i++)
	{
		if (id == info[i].ID)
		{
			num = i;
			break;
		}
	}
	if (num == -1) {
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}
	else {
		cout << "�Աݾ�: ";
		cin >> money;
		info[num].money += money;
		cout << "�ԱݿϷ�" << endl;
	}
}

void Withdraw(void)
{
	int id, num = -1, i, money;
	cout << "[���]" << endl;
	cout << "����ID: ";
	cin >> id;
	for (i = 0; i < 100; i++)
	{
		if (id == info[i].ID)
		{
			num = i;
			break;
		}
	}
	if (num == -1) {
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}
	else {
		cout << "��ݾ�: ";
		cin >> money;
		info[num].money -= money;
		cout << "��ݿϷ�" << endl;
	}
}

void PrintAll(void)
{
	cout << "[�������� ��ü ���]" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "����ID: " << info[i].ID << endl;
		cout << "�̸�: " << info[i].name << endl;
		cout << "�ܾ�: " << info[i].money << endl;
		cout << endl;
	}
}