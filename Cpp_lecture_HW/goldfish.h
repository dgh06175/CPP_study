#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // GoldFish는 pet을부터 상속받을거기 때문
#include "IAquaticAnimal.h" // GoldFish는 수중행물이기 때문

class GoldFish : public Pet, public IAquaticAnimal
{
public:
	GoldFish(string name, PetKind pk, int age)
		: Pet("금붕어", name, pk, age)
	{}
	void swim() {
		cout << "물 속에서 헤엄칩니다" << endl;
	}
};