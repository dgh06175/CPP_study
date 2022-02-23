#include<iostream>
#include "pet.h"

void Pet::eat()   // "먹이를 먹습니다" 메세지 출력하기
{
	cout << species <<" 먹이를 먹습니다" << endl;
}
void Pet::view()  // 애완동물 정보를 한줄로 출력하기
{
	cout << this->name;
	switch (this->kind) {
	case MAMMAL: cout << " (포유류) "; break;
	case FISH: cout << " (어류) "; break;
	case BIRDS: cout << " (조류) "; break;
	case UNKNOWN: cout << " (미확인 생물체) "; break;
	}
	cout << this->age << "살" << endl;
}
