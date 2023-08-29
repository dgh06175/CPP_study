#pragma once
// Fitness.h는 문제에서 주어짐
class Fitness
{
private:
	int num;
	char* name;
	double weight;
	double height;

public:
	// 생성자 함수, 소멸자 함수
	Fitness();
	Fitness(int num, char* name, double weight, double height);
	Fitness(Fitness& r);
	~Fitness();

	// 연산자 함수
	Fitness& operator = (Fitness& r);
	bool operator==(Fitness& r);

	//setter, getter 함수
	void setNum(int num);
	int getNum();
	void setName(char* name);
	char* getName();
	void setWeight(double weight);
	double getWeight();
	void setHeight(double height);
	double getHeight();

	//기타멤버함수
	double bmi(); // 해당 회원의 bmi를 계산하여 리턴 하는 함수
};