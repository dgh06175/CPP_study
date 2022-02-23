#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // Duck�� pet������ ��ӹ����ű� ����
#include "ILandAnimal.h" // Duck�� ���󵿹��̱� ����
#include "IAquaticAnimal.h" // Duck �� �����๰�̱⵵ �ϱ� ����

class Duck : public Pet, public ILandAnimal, public IAquaticAnimal
{
public:
	Duck(string name, PetKind pk, int age)
		: Pet("����", name, pk, age)
	{}
	void creep() { // �������̵� ������
		cout << "�� ������ �ι߷� �Ƚ��ϴ�" << endl;
	}
	void swim() {
		cout << "�� �ӿ��� �ι߷� ���Ĩ�ϴ�" << endl;
	}
};