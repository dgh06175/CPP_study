#include <iostream>
using namespace std;
#pragma	warning (disable:4996)

/* Racingcar.cpp */
//#define ID_LEN 20
//#define MAX_SPD 200
//#define FUEL_STEP 2
//#define ACC_STEP 10
//#define BRK_STEP 10
//
///* ����ü �ۿ� �Լ��� ������ */
//struct Car
//{
//	char ID[ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//};
//
//void ShowCarState(const Car& car)
//{
//	cout << "������ ID: " << car.ID << endl;
//	cout << "���ᷮ: " << car.fuelGauge << "%" << endl;
//	cout << "����ӵ�: " << car.curSpeed << "km/s" << endl;
//}
//
//void Accel(Car& car)
//{
//	cout << car.ID << "����" << endl;
//	if (car.fuelGauge <= 0) return;
//	else car.fuelGauge -= FUEL_STEP;
//
//	if (car.curSpeed + ACC_STEP >= MAX_SPD)
//	{
//		car.curSpeed = MAX_SPD;
//		return;
//	}
//
//	car.curSpeed += ACC_STEP;
//}
//
//void Break(Car& car)
//{
//	cout << car.ID << "�극��" << endl;
//	if (car.curSpeed < BRK_STEP)
//	{
//		car.curSpeed = 0;
//		return;
//	}
//
//	car.curSpeed -= BRK_STEP;
//}
//
//int main(void)
//{
//	Car run99 = { "run99", 100, 0 };
//	Accel(run99);
//	Accel(run99);
//	ShowCarState(run99);
//	Break(run99);
//	ShowCarState(run99);
//
//	Car sped77 = { "sped77",100,0 };
//	Accel(sped77);
//	Accel(sped77);
//	Accel(sped77);
//	Accel(sped77);
//	Break(sped77);
//	ShowCarState(sped77);
//}
///* ����ü �ȿ� �Լ��� ���� �� */
//namespace CAR_CONST
//{
//	enum
//	{
//		ID_LEN = 20,
//		MAX_SPD = 200,
//		FUEL_STEP = 2,
//		ACC_STEP = 10,
//		BRK_STEP = 10
//	};
//}
//
//struct Car
//{
//	char ID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//
//	void ShowCarState(); // �������� ���
//	void Accel();		 // ����, �ӵ�����
//	void Break();		 // �극��ũ, �ӵ�����
//};
//
//int main(void)
//{
//	Car run99 = { "run99", 100, 0 };
//	run99.Accel();
//	run99.Accel();
//	run99.ShowCarState();
//	run99.Break();
//	run99.ShowCarState();
//
//	Car sped77 = { "sped77",100,0 };
//	sped77.Accel();
//	sped77.Accel();
//	sped77.Break();
//	sped77.ShowCarState();
//	return 0;
//}
//
//inline void Car::ShowCarState()
//{
//	cout << "������ ID: " << ID << endl;
//	cout << "���ᷮ: " << fuelGauge << "%" << endl;
//	cout << "����ӵ�: " << curSpeed << "km/s" << endl;
//}
//
//inline void Car::Accel()
//{
//	cout << ID << "����" << endl;
//	if (fuelGauge <= 0) return;
//	else fuelGauge -= CAR_CONST::FUEL_STEP;
//	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
//	{
//		curSpeed = CAR_CONST::MAX_SPD;
//		return;
//	}
//	curSpeed += CAR_CONST::ACC_STEP;
//}
//
//inline void Car::Break()
//{
//	cout << ID << "�극��" << endl;
//	if (curSpeed < CAR_CONST::BRK_STEP)
//	{
//		curSpeed = 0;
//		return;
//	}
//	curSpeed -= CAR_CONST::BRK_STEP;
//}

/* p114 ���� 03-1 */
//
//struct Point
//{
//	int xpos;
//	int ypos;
//	
//	void MovePos(int x, int y)
//	{
//		xpos += x;
//		ypos += y;
//	}
//	void AddPoint(const Point& pos)
//	{
//		xpos += pos.xpos;
//		ypos += pos.ypos;
//	}
//	void ShowPosition()
//	{
//		cout << "[" << xpos << ", " << ypos << "]" << endl;
//	}
//};
//
//int main(void)
//{
//	Point pos1 = { 12, 4 };
//	Point pos2 = { 20, 30 };
//
//	pos1.MovePos(-7, 10);
//	pos1.ShowPosition();
//
//	pos1.AddPoint(pos2);
//	pos1.ShowPosition();
//	return 0;
//}

///* RacingCarClassBase.cpp */
//#include <cstring>
//namespace CAR_CONST
//{
//	enum
//	{
//		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
//		ACC_STEP = 10, BRK_STEP = 10
//	};
//}
//
//class Car
//{
//private:
//	char gamerID[CAR_CONST::ID_LEN];
//	int fuelGauge;
//	int curSpeed;
//public:
//	void InitMembers(char* ID, int fuel);
//	void ShowCarState(); // �������� ���
//	void Accel();		 // ����, �ӵ�����
//	void Break();		 // �극��ũ, �ӵ�����
//};
//
//void Car::InitMembers(char* ID, int fuel)
//{
//	strcpy(gamerID, ID);
//	fuelGauge = fuel;
//	curSpeed = 0;
//}
//
//int main(void)
//{
//	Car run99;
//	run99.InitMembers( "run99", 100 );
//	run99.Accel();
//	run99.Accel();
//	run99.ShowCarState();
//	run99.Break();
//	return 0;
//}
//
//inline void Car::ShowCarState()
//{
//	cout << "������ ID: " << gamerID << endl;
//	cout << "���ᷮ: " << fuelGauge << "%" << endl;
//	cout << "����ӵ�: " << curSpeed << "km/s" << endl;
//}
//
//inline void Car::Accel()
//{
//	cout << gamerID << "����" << endl;
//	if (fuelGauge <= 0) return;
//	else fuelGauge -= CAR_CONST::FUEL_STEP;
//	if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
//	{
//		curSpeed = CAR_CONST::MAX_SPD;
//		return;
//	}
//	curSpeed += CAR_CONST::ACC_STEP;
//}
//
//inline void Car::Break()
//{
//	cout << gamerID << "�극��" << endl;
//	if (curSpeed < CAR_CONST::BRK_STEP)
//	{
//		curSpeed = 0;
//		return;
//	}
//	curSpeed -= CAR_CONST::BRK_STEP;
//}
//
//inline void InitMembers(char* ID)/

//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	cout << "�ȳ�";
//}

//#include <string>
//
//int main(void)
//{
//	string s;
//	int n = 100000;
//	for (int i = 0; i < n; i++) {
//		s += "aa";
//	}
//}
