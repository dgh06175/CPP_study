#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // GoldFish�� pet������ ��ӹ����ű� ����
#include "IAquaticAnimal.h" // GoldFish�� �����๰�̱� ����

class GoldFish : public Pet, public IAquaticAnimal
{
public:
	GoldFish(string name, PetKind pk, int age)
		: Pet("�ݺؾ�", name, pk, age)
	{}
	void swim() {
		cout << "�� �ӿ��� ���Ĩ�ϴ�" << endl;
	}
};