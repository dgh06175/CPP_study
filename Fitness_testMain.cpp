#include <iostream>
#include "Fitness.h"
#include <iomanip>
using namespace std;

void MyFlush() {
	cin.clear();
	while (cin.get() != '\n');
}

// 메뉴를 출력하고 사용자가 선택한 메뉴의 번호를 리턴하는 함수
int PrintMenu(void)
{
	int menu;
	cout << "======================================================\n";
	cout << "1. 회원등록\n2. 회원전체보기\n3. 회원정보검색\n4. 회원탈퇴\n5. 특별관리회원\n6. 종료" << endl;
	cout << "======================================================\n";
	cout << "실행할 메뉴의 번호를 선택하세요 : ";
	cin >> menu; // 에너지 입력받기
	while (cin.fail() || menu < 1 || menu > 6) { // 문자가 들어갔거나, 음수를 받았을 경우 재입력 요구
		MyFlush();
		cout << "잘못된 번호입니다. 번호를 다시 입력하세요 : ";
		cin >> menu;
	}
	return menu;
}

// 회원 등록 함수
Fitness* Menu_1(int memberCnt)
{
	char name[20];
	double weight;
	double height;
	cout << "\n회원 등록을 진행합니다.\n회원의 이름을 입력하세요 : ";
	cin >> name;
	cout << "회원의 몸무게를 입력하세요 : ";
	cin >> weight;
	cout << "회원의 키를 입력하세요 : ";
	cin >> height;
	cout << endl;
	Fitness* member_info = new Fitness(memberCnt + 1, name, weight, height);
	return member_info;
}

// 회원정보 출력 함수
void Menu_2(Fitness* fAry[100], int memberCnt)
{
	cout << '\n' << setw(4) << "번호" << setw(12) << "이름" << setw(12) << "몸무게(kg)" << setw(12) << "키(cm)" << endl;
	for (int i = 0; i < memberCnt; i++) {
		cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
		cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
	}
	cout << '\n';
}

// 회원정보 검색 함수 (동명이인 가능)
void Menu_3(Fitness* fAry[100], int memberCnt)
{
	char name[20];
	cout << "검색할 회원의 이름을 입력하세요 : ";
	cin >> name;

	bool isExist = false;
	for (int i = 0; i < memberCnt; i++) {
		if (strcmp(fAry[i]->getName(), name) == 0) {
			isExist = true;
			break;
		}
	}

	if (isExist) {
		cout << "\n\n" << setw(4) << "번호" << setw(12) << "이름" << setw(12) << "몸무게(kg)" << setw(12) << "키(cm)" << endl;
		for (int i = 0; i < memberCnt; i++) {
			if (strcmp(fAry[i]->getName(), name) == 0) {
				cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
				cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
			}
		}
	}
	else {
		cout << '\n' << name << " 님의 정보가 없습니다.";
	}
	cout << "\n\n";
}

// 회원정보 삭제 함수
int Menu_4(Fitness* fAry[100], int memberCnt) {
	char name[20];
	cout << "탈퇴할 회원의 이름을 입력하세요 : ";
	cin >> name;

	int member_index = -1;
	for (int i = 0; i < memberCnt; i++) {
		if (strcmp(fAry[i]->getName(), name) == 0) {
			member_index = i;
			break;
		}
	}

	if (member_index == -1) {
		cout << '\n' << name << " 님의 정보가 없습니다.";
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
		cout << name << "회원의 정보가 삭제되었습니다.\n";
		return memberCnt - 1;
	}
}

// 특별관리회원 출력 함수
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
		cout << "bmi가 25 이상인 특별 관리 회원들의 정보를 출력합니다.\n";
		cout << "\n" << setw(4) << "번호" << setw(12) << "이름" << setw(12) << "몸무게(kg)" << setw(12) << "키(cm)" << endl;
		for (int i = 0; i < memberCnt; i++) {
			if (fAry[i]->bmi() > 25.0) {
				cout << setw(4) << fAry[i]->getNum() << setw(12) << fAry[i]->getName();
				cout << setw(12) << fAry[i]->getWeight() << setw(12) << fAry[i]->getHeight() << endl;
			}
		}
	}
	else {
		cout << "특별 관리 대상인 회원이 없습니다.";
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
		case 1: // 1. 회원등록
		{
			Fitness* a = new Fitness;
			a = Menu_1(memberCnt);
			fAry[memberCnt++] = a;
			break;
		}
		case 2: // 2. 회원전체보기
		{
			Menu_2(fAry, memberCnt);
			break;
		}
		case 3: // 3. 회원정보검색
		{
			Menu_3(fAry, memberCnt);
			break;
		}
		case 4: // 4. 회원탈퇴
		{
			memberCnt = Menu_4(fAry, memberCnt);
			break;
		}
		case 5: // 5. 특별관리회원
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
	cout << "삭제완료";
	return 0;
}