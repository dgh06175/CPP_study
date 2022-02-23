#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // Duck은 pet을부터 상속받을거기 때문
#include "ILandAnimal.h" // Duck은 육상동물이기 때문
#include "IAquaticAnimal.h" // Duck 은 수중행물이기도 하기 때문

class Duck : public Pet, public ILandAnimal, public IAquaticAnimal
{
public:
	Duck(string name, PetKind pk, int age)
		: Pet("오리", name, pk, age)
	{}
	void creep() { // 오버라이드 해줬음
		cout << "땅 위에서 두발로 걷습니다" << endl;
	}
	void swim() {
		cout << "물 속에서 두발로 헤엄칩니다" << endl;
	}
};