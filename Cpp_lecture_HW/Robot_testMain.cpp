#include <iostream>
using namespace std;
#include "Robot.h"

/*--------------------------------------������� �ۼ�--------------------------------------*/
// rp��ü �迭�� �ȿ� name�� �̹� ������ �ش� �迭�� index ����, ������� -1 ���� �̸��� ������ rp��ü�� ������ num��
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

// cin �ʱ�ȭ, cin ����ó���� ���
void MyFlush() {
	cin.clear();
	while (cin.get() != '\n');
}

// �κ��� ������ �κ����� �̸��� ������ ������ ���� �Է¹޴� �Լ�
void input(Robot* rp, int cnt)
{
	for (int num = 0; num < cnt; num++) {
		char name[20];
		cout << '\n' << num + 1 << "�� �κ����� �Է��Ͻÿ� : ";
		cin >> name; // �̸� �Է¹ޱ�
		while (cin.fail() || IsNameExist(rp, name, num)) { // �ߺ��˻�, ���Է� �䱸
			MyFlush();
			cout << "�ߺ��� �̸��Դϴ�. " << num + 1 << "�� �κ����� �ٽ� �Է��Ͻÿ� : ";
			cin >> name;
		}
		rp[num].setName(name);

		int energy;
		cout << rp[num].getName() << "�� ������ ���� �Է��Ͻÿ� : ";
		cin >>energy; // ������ �Է¹ޱ�
		while (cin.fail() || energy < 0) { // ���ڰ� ���ų�, ������ �޾��� ��� ���Է� �䱸
			MyFlush();
			cout << "�߸��� �����Դϴ�. " << rp[num].getName() << "�� ������ ���� �ٽ� �Է��Ͻÿ� : ";
			cin >> energy;
		}
		rp[num].setEnergy(energy);
	}
}

// � �κ��� ���� ���� �� �� ����ϴ� �Լ�
void work(Robot* rp, int cnt)
{
	char selected_name[20];
	while (1) {
		cout << "\n# �κ��� ����("; // �κ� ���� �ȳ����� ���
		for (int i = 0; i < cnt; i++) {
			if (i != 0) { cout << ", "; }
			cout << rp[i].getName();
		}
		cout << ") : ";

		MyFlush(); // cin.getline�� ���๮�ڸ� �����ϰ� ��� ���ڸ� �����Ƿ� ���๮�ڰ� �����ִ� cin ���۸� ����ش�.
		cin.getline(selected_name, sizeof(selected_name));
		if (selected_name[0] == '\0') { break; } // �ƹ��͵� �Է����� �ʰ� ���͸� �Է�������� ���� ����
		while (cin.fail() || !IsNameExist(rp, selected_name, cnt)) { // �߸��� ������ �Էµưų�, �������� �ʴ� �κ��̸��� �Է����� ��� ���Է� �䱸
			MyFlush();
			cout << "�������� �ʴ� �κ��Դϴ�. �κ����� �ٽ� �Է����ּ��� : ";
			cin >> selected_name;
		}

		int number_of_robot = ReturnRobotNameIndex(rp, selected_name, cnt); // �Է��� �κ��� rp�迭���� ���° �ε������� ����

		cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
		int todo_num;
		cin >> todo_num;
		while (cin.fail() || todo_num < 1 || todo_num > 5) {
			MyFlush();
			cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ��� : ";
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
			cout << "# ������ �������� �Է� : ";
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
/*--------------------------------------������� �ۼ�--------------------------------------*/

int main()
{
	Robot* rp;
	int cnt;
	cout << "������ �κ� ����� �Է��Ͻÿ� : ";
	cin >> cnt; // �����Է� ����ó��
	rp = new Robot[cnt]; // �κ� ��ü �迭 ����
	input(rp, cnt); // �ߺ��̸� ���Է� �䱸
	work(rp, cnt); // ���� �κ��� �Է½� ���Է� �䱸, ����Ű �Է½� ����. cin.getline�̿�
	prn(rp, cnt);
	delete[] rp;
	return 0;
}