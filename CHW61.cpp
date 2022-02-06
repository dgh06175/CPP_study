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
	cout << "�˻��� ���� : ";
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
		int ary[100] = {}; // ary[0]���� �������� ������ ����, �������� �˻��� ������ ���� �迭 ����

		int i = 0;
		do {
			cin >> ary[i++];
		} while (getc(stdin) == ' '); // ���Ͱ� ������ �Է� ����

		int sub_ary[99] = {}; // ������ ������ ���� ���̵��� ������ �迭 ����

		int index = 0;
		for (int i = 1; i < ary[0]; i++) { // ������ ���� ���̸� �������� ����
			sub_ary[index++] = my_fabs(ary[i] - ary[i + 1]); // ary[0]�� ������ ������ �����̹Ƿ� ary[1]���� �˻�
		}

		sort(sub_ary, sub_ary + ary[0] - 1); // ������ ���� ���̵��� ������������ ����

		bool is_true = true;
		for (int i = 0; i < ary[0] - 1; i++) {
			if (sub_ary[i] != i + 1)is_true = false;
			// sub_ary �迭���� ���ڰ� 1���� ary[0]-1 ���� ������� ����Ǿ��־�� �Ѵ�.
		}

		my_output(is_true, ary);
	}
}