#include <iostream>
using namespace std;

/*
HW 58
����� ����
1 <= N <= 10

# ��/���� �� �Է� 5(����)
 1  2  3  4  5
16 17 18 19  6
15 24 25 20  7
14 23 22 21  8
13 12 11 10  9

# ��/���� �� �Է� 6(����)
 1  2  3  4  5  6
20 21 22 23	24  7
19 32 33 34 25  8
18 31 36 35 26  9
17 30 29 28 27 10
16 15 14 13 12 11
*/

int main()
{
	int ary[10][10] = { 0, };
	int n;
	cout << "# ��/���� �� �Է� ";
	cin >> n;
	while (cin.fail()) { // �Է� ����ó��
		cin.clear();
		while (cin.get() == '\n');
		cin >> n;
	}

	for (int i = 0; i < n; i++) { // ù��°�� �̸� �ϼ�
		ary[0][i] = i + 1;
	}

	int x = 0, y = n - 1; // ary[0][n-1] ��ġ���� ����
	int k = n;
	for (int i = n - 1; i > 0; i-=2) {
		for (int j = 0; j < i; j++) {
			x = x + 1;
			ary[x][y] = ++k;
		}
		for (int j = 0; j < i; j++) {
			y = y - 1;
			ary[x][y] = ++k;
		}
		for (int j = 0; j < i - 1; j++) {
			x = x - 1;
			ary[x][y] = ++k;
		}
		for (int j = 0; j < i - 1; j++) {
			y = y + 1;
			ary[x][y] = ++k;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", ary[i][j]);
		}
		printf("\n");
	}
}