#include<iostream>
using namespace std;
#include "Robot.h"
#pragma warning(disable:4996)

/*--------------------------------------������� �ۼ�--------------------------------------*/
void Robot::errPrn()
{
	cout << this->name << "�� �������� �����մϴ�. ���� ������ : " << this->energy << endl;
}

Robot::Robot() // name�� Null string����, energy�� 0���� �ʱ�ȭ
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

Robot::Robot(const Robot& r) // ��������� deep copy constructor
{
	this->setEnergy(r.energy);
	this->setName(r.name);
}

Robot::~Robot()
{
	delete[] this->name;
}

void Robot::go() // ���� �޽��� ��� �� ������ 10 ����
{
	if (this->energy < 10) {
		this->errPrn();
		return;
	}
	cout << this->name << " ����..." << endl;
	this->energy -= 10;
}

void Robot::back() // ���� �޽��� ��� �� ������ 20 ����
{
	if (this->energy < 20) {
		this->errPrn();
		return;
	}
	cout << this->name << " ����..." << endl;
	this->energy -= 20;
}

void Robot::turn() // �� �޽��� ��� �� ������ 30 ����
{
	if (this->energy < 30) {
		this->errPrn();
		return;
	}
	cout << this->name << " ȸ��..." << endl;
	this->energy -= 30;
}

void Robot::jump() // ���� �޽��� ��� �� ������ 40 ����
{
	if (this->energy < 40) {
		this->errPrn();
		return;
	}
	cout << this->name << " ����..." << endl;
	this->energy -= 40;
}

void Robot::charge(int e) // e�� ��ŭ ���� (�������ڰ� ������ ��� �������� ����)
{
	if (e < 0)e = 0;
	cout << this->name << " ������" << e << " ����..." << endl;
	this->energy += e;
}

char* Robot::getName() // name����� �� ����
{
	return this->name;
}

void Robot::setName(const char* newName) // name����� ���� ���޵� ���ڿ��� �� �ʱ�ȭ (��������)
{
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}

int Robot::getEnergy() // energy����� �� ����  
{
	return this->energy;
}

void Robot::setEnergy(int newEnergy) // energy����� ���� ���޵� ���ڷ� �� �ʱ�ȭ(�������ڰ� �����϶��� 0���� �ʱ�ȭ 
{
	this->energy = newEnergy;
}

/*--------------------------------------������� �ۼ�--------------------------------------*/