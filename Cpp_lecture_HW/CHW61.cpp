#include <iostream>
#include <algorithm>
using namespace std;

int my_fabs(int num) {
	if (num > 0)
		return num;
	else
		return -num;
}

void my_output(bool is_true, int ary[]) {
	cout << "검사한 수열 : ";
	for (int i = 1; i <= ary[0]; i++) {
		cout << ary[i] << ' ';
	}
	if (is_true) {
		cout << "(Jolly jumper)" << endl;
	}
	else {
		cout << "(Not jolly jumper)" << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int ary[100] = {}; // ary[0]에는 수열내의 숫자의 개수, 나머지는 검사할 수열을 받을 배열 선언

		int i = 0;
		do {
			cin >> ary[i++];
		} while (getc(stdin) == ' '); // 엔터가 나오면 입력 종료

		int sub_ary[99] = {}; // 수열의 인접한 수의 차이들을 저장할 배열 선언

		int index = 0;
		for (int i = 1; i < ary[0]; i++) { // 인접한 수의 차이를 절댓값으로 저장
			sub_ary[index++] = my_fabs(ary[i] - ary[i + 1]); // ary[0]은 수열의 숫자의 개수이므로 ary[1]부터 검사
		}

		sort(sub_ary, sub_ary + ary[0] - 1); // 저장한 수의 차이들을 오름차순으로 정렬

		bool is_true = true;
		for (int i = 0; i < ary[0] - 1; i++) {
			if (sub_ary[i] != i + 1)is_true = false;
			// sub_ary 배열에는 숫자가 1부터 ary[0]-1 까지 순서대로 저장되어있어야 한다.
		}

		my_output(is_true, ary);
	}
}