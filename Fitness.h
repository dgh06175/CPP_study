#pragma once
// Fitness.h�� �������� �־���
class Fitness
{
private:
	int num;
	char* name;
	double weight;
	double height;

public:
	// ������ �Լ�, �Ҹ��� �Լ�
	Fitness();
	Fitness(int num, char* name, double weight, double height);
	Fitness(Fitness& r);
	~Fitness();

	// ������ �Լ�
	Fitness& operator = (Fitness& r);
	bool operator==(Fitness& r);

	//setter, getter �Լ�
	void setNum(int num);
	int getNum();
	void setName(char* name);
	char* getName();
	void setWeight(double weight);
	double getWeight();
	void setHeight(double height);
	double getHeight();

	//��Ÿ����Լ�
	double bmi(); // �ش� ȸ���� bmi�� ����Ͽ� ���� �ϴ� �Լ�
};