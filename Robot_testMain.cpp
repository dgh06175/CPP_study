#include <iostream>
using namespace std;
#include "Robot.h"

/*--------------------------------------여기부터 작성--------------------------------------*/
// rp객체 배열들 안에 name이 이미 있으면 해당 배열의 index 리턴, 없을경우 -1 리턴 이름이 정해진 rp객체의 개수는 num개
int ReturnRobotNameIndex(Robot* rp, char* name, int num)
{
	for (int i = 0; i < num; i++) {
		if (strcmp(rp[i].getName(), name) == 0) { return i; }
	}
	return -1;
}

bool IsNameExist(Robot* rp, char* name, int num)
{
	for (int i = 0; i < num; i++) {
		if (strcmp(rp[i].getName(), name) == 0) { return true; }
	}
	return false;
}

// cin 초기화, cin 예외처리에 사용
void MyFlush() {
	cin.clear();
	while (cin.get() != '\n');
}

// 로봇의 개수와 로봇들의 이름과 각각의 에너지 양을 입력받는 함수
void input(Robot* rp, int cnt)
{
	for (int num = 0; num < cnt; num++) {
		char name[20];
		cout << '\n' << num + 1 << "번 로봇명을 입력하시오 : ";
		cin >> name; // 이름 입력받기
		while (cin.fail() || IsNameExist(rp, name, num)) { // 중복검사, 재입력 요구
			MyFlush();
			cout << "중복된 이름입니다. " << num + 1 << "번 로봇명을 다시 입력하시오 : ";
			cin >> name;
		}
		rp[num].setName(name);

		int energy;
		cout << rp[num].getName() << "의 에너지 양을 입력하시오 : ";
		cin >>energy; // 에너지 입력받기
		while (cin.fail() || energy < 0) { // 문자가 들어갔거나, 음수를 받았을 경우 재입력 요구
			MyFlush();
			cout << "잘못된 정보입니다. " << rp[num].getName() << "의 에너지 양을 다시 입력하시오 : ";
			cin >> energy;
		}
		rp[num].setEnergy(energy);
	}
}

// 어떤 로봇이 무슨 일을 할 지 명령하는 함수
void work(Robot* rp, int cnt)
{
	char selected_name[20];
	while (1) {
		cout << "\n# 로봇명 선택("; // 로봇 선택 안내문구 출력
		for (int i = 0; i < cnt; i++) {
			if (i != 0) { cout << ", "; }
			cout << rp[i].getName();
		}
		cout << ") : ";

		MyFlush(); // cin.getline은 개행문자를 제외하고 모든 문자를 받으므로 개행문자가 남아있는 cin 버퍼를 비워준다.
		cin.getline(selected_name, sizeof(selected_name));
		if (selected_name[0] == '\0') { break; } // 아무것도 입력하지 않고 엔터를 입력했을경우 루프 종료
		while (cin.fail() || !IsNameExist(rp, selected_name, cnt)) { // 잘못된 정보가 입력됐거나, 존재하지 않는 로봇이름을 입력했을 경우 재입력 요구
			MyFlush();
			cout << "존재하지 않는 로봇입니다. 로봇명을 다시 입력해주세요 : ";
			cin >> selected_name;
		}

		int number_of_robot = ReturnRobotNameIndex(rp, selected_name, cnt); // 입력한 로봇이 rp배열에서 몇번째 인덱스인지 저장

		cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
		int todo_num;
		cin >> todo_num;
		while (cin.fail() || todo_num < 1 || todo_num > 5) {
			MyFlush();
			cout << "잘못 입력하셨습니다. 다시 입력해주세요 : ";
			cin >> todo_num;
		}

		switch (todo_num)
		{
		case 1:
			rp[number_of_robot].go();
			break;
		case 2:
			rp[number_of_robot].back();
			break;
		case 3:
			rp[number_of_robot].turn();
			break;
		case 4:
			rp[number_of_robot].jump();
			break;
		case 5:
			int energy;
			cout << "# 충전할 에너지양 입력 : ";
			cin >> energy;
			rp[number_of_robot].charge(energy);
			break;
		default:
			break;
		}
	}
}

void prn(Robot* rp, int cnt)
{
	cout << '\n';
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << ". " << rp[i].getName() << " : " << rp[i].getEnergy() << endl;
	}
}
/*--------------------------------------여기까지 작성--------------------------------------*/

int main()
{
	Robot* rp;
	int cnt;
	cout << "구입할 로봇 대수를 입력하시오 : ";
	cin >> cnt; // 문자입력 예외처리
	rp = new Robot[cnt]; // 로봇 객체 배열 생성
	input(rp, cnt); // 중복이름 재입력 요구
	work(rp, cnt); // 없는 로봇명 입력시 재입력 요구, 엔터키 입력시 종료. cin.getline이용
	prn(rp, cnt);
	delete[] rp;
	return 0;
}