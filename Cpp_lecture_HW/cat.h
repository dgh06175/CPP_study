#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // cat�� pet������ ��ӹ����ű� ����
#include "ILandAnimal.h" // cat�� ���󵿹��̱� ����

class Cat : public Pet, public ILandAnimal
{
public:
	Cat(string name, PetKind pk, int age)
		: Pet("�����", name, pk, age)
	{}
	void creep() { // �������̵� ������
		cout << "�� ������ ��ӻ�� �Ƚ��ϴ�" << endl;
	}
};