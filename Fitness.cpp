#include <iostream>
#include "Fitness.h"
using namespace std;
#pragma warning(disable:4996)


// ȸ����ȣ 0, ���� null string, ������ 0, ���� 0���� �ʱ�ȭ
Fitness::Fitness():num(0), weight(0), height(0)
{
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");
}

// �Ű������� ���� ������ �ʱ�ȭ
Fitness::Fitness(int num, char* name, double weight, double height) :num(num), weight(weight), height(height)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

// r��ü�� ������ �ʱ�ȭ
Fitness::Fitness(Fitness& r) :num(r.num), weight(r.weight), height(r.height)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
}

// �Ҹ���
Fitness::~Fitness()
{
	delete[] name;
}

// ���Կ����� �Լ�
Fitness& Fitness::operator = (Fitness& r)
{
	if (this == &r)return *this;
	delete[] name;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->num = r.num;
	this->weight = r.weight;
	this->height = r.height;
	return *this;
}

bool Fitness::operator==(Fitness& r)
{
	if (this == &r)return true;
	else if (strcmp(this->name, r.name) == 0 && this->num == r.num && this->weight == r.weight && this->height == r.height) {
		return true;
	}
	else return false;
}

//setter, getter �Լ�
void Fitness::setNum(int num)
{
	this->num = num;
}
int Fitness::getNum()
{
	return this->num;
}
void Fitness::setName(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char* Fitness::getName()
{
	return this->name;
}
void Fitness::setWeight(double weight)
{
	this->weight = weight;
}
double Fitness::getWeight()
{
	return this->weight;
}
void Fitness::setHeight(double height)
{
	this->height = height;
}
double Fitness::getHeight()
{
	return this->height;
}

// �ش� ȸ���� bmi�� ����Ͽ� ���� �ϴ� �Լ�
double Fitness::bmi()
{
	return this->weight / ((this->height/100) * (this->height/100));
}