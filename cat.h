#pragma once
#include <iostream>
using namespace std;
#include "pet.h" // cat은 pet을부터 상속받을거기 때문
#include "ILandAnimal.h" // cat은 육상동물이기 때문

class Cat : public Pet, public ILandAnimal
{
public:
	Cat(string name, PetKind pk, int age)
		: Pet("고양이", name, pk, age)
	{}
	void creep() { // 오버라이드 해줬음
		cout << "땅 위에서 사뿐사뿐 걷습니다" << endl;
	}
};