#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool is_in(int num, int ary[]) // 중복되는 난수인지 알려주는 함수
{
	for (int i = 0; i < 4; i++) {
		if (ary[i] == num) return true;
	}
	return false;
}

void make_computer_nums(int computer_nums[]) { // 중복되지 않는 난수로 초기화 하는 함수
	for (int i = 0; i < 4; i++) {
		int random_num = rand() % 10;
		while (is_in(random_num, computer_nums)) {
			random_num = rand() % 10;
		}
		computer_nums[i] = random_num;
	}
}

int ball_count(int user_nums[], int computer_nums[], int strike) { // 볼카운트 체크 함수
	int ball = 0;
	for (int i = 0; i < 4; i++) {
		if (is_in(user_nums[i], computer_nums)) ball += 1;
	}
	return ball - strike; // 방금 계산한 ball은 strike의 경우도 포함하므로 빼준다.
}

bool print_result(int ball, int strike) { // 결과출력함수
	if (ball + strike == 0) {
		cout << "No!" << '\n';
		return false;
	}
	else if (strike == 4) {
		cout << "OK!!!" << '\n';
		return true;
	}
	else {
		cout << strike << "S " << ball << "B\n";
		return false;
	}
}


int main()
{
	srand((unsigned int)time(NULL)); // rand() 사용을 위한 코드
	int computer_nums[4] = { -1,-1,-1,-1 };
	make_computer_nums(computer_nums);

	cout << "컴퓨터의 숫자는" << '\n';
	for (auto i : computer_nums) { // 컴퓨터의 숫자(정답) 출력
		cout << i << ' ';
	}
	cout << endl;


	int user_nums[4];
	bool is_correct = false;
	int attempt = 1;
	while (!is_correct) { // 정답이 아니면 무한 반복
		cout << "# " << attempt++ << "차 :";
		for (int i = 0; i < 4; i++) {
			cin >> user_nums[i];
		}

		int strike = 0;
		for (int i = 0; i < 4; i++) { // 스트라이크 계산
			if (computer_nums[i] == user_nums[i]) strike += 1;
		}
		int ball = ball_count(user_nums, computer_nums, strike); // ball 계산
		is_correct = print_result(ball, strike); // 결과를 출력하고 정답이면 true 반환하는 함수 print_result
	}
}