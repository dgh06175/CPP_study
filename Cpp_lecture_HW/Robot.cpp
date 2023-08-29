#include<iostream>
using namespace std;
#include "Robot.h"
#pragma warning(disable:4996)

/*--------------------------------------여기부터 작성--------------------------------------*/
void Robot::errPrn()
{
	cout << this->name << "의 에너지가 부족합니다. 남은 에너지 : " << this->energy << endl;
}

Robot::Robot() // name은 Null string으로, energy는 0으로 초기화
{
	this->name = new char[1];
	strcpy(this->name, "");
	this->energy = 0;
}

Robot::Robot(const char* name, int energy)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(const Robot& r) // 복사생성자 deep copy constructor
{
	this->setEnergy(r.energy);
	this->setName(r.name);
}

Robot::~Robot()
{
	delete[] this->name;
}

void Robot::go() // 전진 메시지 출력 후 에너지 10 감소
{
	if (this->energy < 10) {
		this->errPrn();
		return;
	}
	cout << this->name << " 전진..." << endl;
	this->energy -= 10;
}

void Robot::back() // 후진 메시지 출력 후 에너지 20 감소
{
	if (this->energy < 20) {
		this->errPrn();
		return;
	}
	cout << this->name << " 후진..." << endl;
	this->energy -= 20;
}

void Robot::turn() // 턴 메시지 출력 후 에너지 30 감소
{
	if (this->energy < 30) {
		this->errPrn();
		return;
	}
	cout << this->name << " 회전..." << endl;
	this->energy -= 30;
}

void Robot::jump() // 점프 메시지 출력 후 에너지 40 감소
{
	if (this->energy < 40) {
		this->errPrn();
		return;
	}
	cout << this->name << " 점프..." << endl;
	this->energy -= 40;
}

void Robot::charge(int e) // e값 만큼 충전 (전달인자가 음수일 경우 에너지값 유지)
{
	if (e < 0)e = 0;
	cout << this->name << " 에너지" << e << " 충전..." << endl;
	this->energy += e;
}

char* Robot::getName() // name멤버의 값 리턴
{
	return this->name;
}

void Robot::setName(const char* newName) // name멤버의 값을 전달된 문자열로 재 초기화 (깊은복사)
{
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

int Robot::getEnergy() // energy멤버의 값 리턴  
{
	return this->energy;
}

void Robot::setEnergy(int newEnergy) // energy멤버의 값을 전달된 숫자로 재 초기화(전달인자가 음수일때는 0으로 초기화 
{
	this->energy = newEnergy;
}

/*--------------------------------------여기까지 작성--------------------------------------*/