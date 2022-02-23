#pragma once
#include<string>
using namespace std;
class Pet  // �ֿϵ��� Ŭ����
{
public : 
	typedef unsigned int age_t; // unsigned int �� age_t��� �θ��ڴ�.
	enum PetKind { MAMMAL, FISH, BIRDS, UNKNOWN }; // ������, ���, ����, �𸣴� ��
private :
	string species; // �� ��
	string name;   // �ֿϵ�����
	PetKind kind;  // ��������
	age_t age;     // ����
public : 
	Pet(string species = "unknown", string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : species(species), name(name), kind(kind), age(age)
	{}
	virtual ~Pet() {} // virtual�� ������ �ڽİ�ü�� �Ҹ��� ����
	virtual void eat();   // "���̸� �Խ��ϴ�" �޼��� ����ϱ�
	void view();  // �ֿϵ��� ������ ���ٷ� ����ϱ�
};