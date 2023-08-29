#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool is_in(int num, int ary[]) // �ߺ��Ǵ� �������� �˷��ִ� �Լ�
{
	for (int i = 0; i < 4; i++) {
		if (ary[i] == num) return true;
	}
	return false;
}

void make_computer_nums(int computer_nums[]) { // �ߺ����� �ʴ� ������ �ʱ�ȭ �ϴ� �Լ�
	for (int i = 0; i < 4; i++) {
		int random_num = rand() % 10;
		while (is_in(random_num, computer_nums)) {
			random_num = rand() % 10;
		}
		computer_nums[i] = random_num;
	}
}

int ball_count(int user_nums[], int computer_nums[], int strike) { // ��ī��Ʈ üũ �Լ�
	int ball = 0;
	for (int i = 0; i < 4; i++) {
		if (is_in(user_nums[i], computer_nums)) ball += 1;
	}
	return ball - strike; // ��� ����� ball�� strike�� ��쵵 �����ϹǷ� ���ش�.
}

bool print_result(int ball, int strike) { // �������Լ�
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
	srand((unsigned int)time(NULL)); // rand() ����� ���� �ڵ�
	int computer_nums[4] = { -1,-1,-1,-1 };
	make_computer_nums(computer_nums);

	cout << "��ǻ���� ���ڴ�" << '\n';
	for (auto i : computer_nums) { // ��ǻ���� ����(����) ���
		cout << i << ' ';
	}
	cout << endl;


	int user_nums[4];
	bool is_correct = false;
	int attempt = 1;
	while (!is_correct) { // ������ �ƴϸ� ���� �ݺ�
		cout << "# " << attempt++ << "�� :";
		for (int i = 0; i < 4; i++) {
			cin >> user_nums[i];
		}

		int strike = 0;
		for (int i = 0; i < 4; i++) { // ��Ʈ����ũ ���
			if (computer_nums[i] == user_nums[i]) strike += 1;
		}
		int ball = ball_count(user_nums, computer_nums, strike); // ball ���
		is_correct = print_result(ball, strike); // ����� ����ϰ� �����̸� true ��ȯ�ϴ� �Լ� print_result
	}
}