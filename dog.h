#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // dog는 pet을부터 상속받을거기 때문
#include "ILandAnimal.h" // dog는 육상동물이기 때문

class Dog : public Pet, public ILandAnimal
{
public:
	Dog(string name, PetKind pk, int age)
		: Pet("개", name, pk, age)
	{}
	void creep() { // 오버라이드 해줬음
		cout << "땅 위에서 네발로 걷습니다" << endl;
	}
};