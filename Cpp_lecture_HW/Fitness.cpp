#include <iostream>
#include "Fitness.h"
using namespace std;
#pragma warning(disable:4996)


// 회원번호 0, 성명 null string, 몸무게 0, 신장 0으로 초기화
Fitness::Fitness():num(0), weight(0), height(0)
{
	this->name = new char[strlen("") + 1];
	strcpy(this->name, "");
}

// 매개변수로 받은 정보로 초기화
Fitness::Fitness(int num, char* name, double weight, double height) :num(num), weight(weight), height(height)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

// r객체의 정보로 초기화
Fitness::Fitness(Fitness& r) :num(r.num), weight(r.weight), height(r.height)
{
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
}

// 소멸자
Fitness::~Fitness()
{
	delete[] name;
}

// 대입연산자 함수
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

//setter, getter 함수
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

// 해당 회원의 bmi를 계산하여 리턴 하는 함수
double Fitness::bmi()
{
	return this->weight / ((this->height/100) * (this->height/100));
}