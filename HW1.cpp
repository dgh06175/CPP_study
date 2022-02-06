#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char name[20];
	cout << "이름 : ";
	cin.getline(name, sizeof(name), '\n');
	cout << "세 과목의 점수 : ";
	int score[3];
	int total_score = 0;
	for (int i = 0; i < 3; i++) {
		cin >> score[i];
		total_score += score[i];
	}
	char blank[11] = "          ";
	char line[61] = "============================================================";
	cout << blank << blank << "=====< 성적표 >=====" << blank << blank<<'\n';
	cout << line << '\n';
	cout << setw(10) << "이름" << setw(10) << "국어" << setw(10) << "영어" << setw(10);
	// setw()로 필드폭 지정
	cout << "수학" << setw(10) << "총점" << setw(10) << "평균" << '\n';
	cout << line << '\n';
	cout << setw(10) << name << setw(10) << score[0] << setw(10) << score[1] << setw(10);
	cout << score[2] << setw(10) << total_score << setw(10);
	cout << fixed << setprecision(2) << (double)total_score / 3.0 << '\n';
	// fixed로 지수 형태로 출력으로 변경
	// setprecision()으로 나타낼 유효 숫자 6(기본)에서 2로 변경
}