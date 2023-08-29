/*
 * Banking System Ver 0.1
 * 작성자 : 이상현
 * 내 용 : OOP 단계별 프로젝트의 기본 틀 구성
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
			cout << "오류 발생" << endl;
		}
	}
	return 0;
}

int Menu(void)
{
	int select;
	cout << "----------Menu----------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> select;
	cout << endl;
	return select;
}

void Make(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> info[n].ID;
	cout << "이름: "; cin >> info[n].name;
	cout << "입금액: "; cin >> info[n].money;
	cout << endl;
	n++;
}

void Deposit(void)
{
	int id, num = -1, i, money;
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
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
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
	else {
		cout << "입금액: ";
		cin >> money;
		info[num].money += money;
		cout << "입금완료" << endl;
	}
}

void Withdraw(void)
{
	int id, num = -1, i, money;
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
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
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
	else {
		cout << "출금액: ";
		cin >> money;
		info[num].money -= money;
		cout << "출금완료" << endl;
	}
}

void PrintAll(void)
{
	cout << "[계좌정보 전체 출력]" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "계좌ID: " << info[i].ID << endl;
		cout << "이름: " << info[i].name << endl;
		cout << "잔액: " << info[i].money << endl;
		cout << endl;
	}
}