#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // dog�� pet������ ��ӹ����ű� ����
#include "ILandAnimal.h" // dog�� ���󵿹��̱� ����

class Dog : public Pet, public ILandAnimal
{
public:
	Dog(string name, PetKind pk, int age)
		: Pet("��", name, pk, age)
	{}
	void creep() { // �������̵� ������
		cout << "�� ������ �׹߷� �Ƚ��ϴ�" << endl;
	}
};