#pragma once
#include<string>
using namespace std;
class Pet  // 애완동물 클래스
{
public : 
	typedef unsigned int age_t; // unsigned int 를 age_t라고 부르겠다.
	enum PetKind { MAMMAL, FISH, BIRDS, UNKNOWN }; // 포유류, 어류, 조류, 모르는 종
private :
	string species; // 종 명
	string name;   // 애완동물명
	PetKind kind;  // 종류구분
	age_t age;     // 연령
public : 
	Pet(string species = "unknown", string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : species(species), name(name), kind(kind), age(age)
	{}
	virtual ~Pet() {} // virtual이 없으면 자식객체가 소멸을 안함
	virtual void eat();   // "먹이를 먹습니다" 메세지 출력하기
	void view();  // 애완동물 정보를 한줄로 출력하기
};