#include<iostream>
#include "pet.h"

void Pet::eat()   // "���̸� �Խ��ϴ�" �޼��� ����ϱ�
{
	cout << species <<" ���̸� �Խ��ϴ�" << endl;
}
void Pet::view()  // �ֿϵ��� ������ ���ٷ� ����ϱ�
{
	cout << this->name;
	switch (this->kind) {
	case MAMMAL: cout << " (������) "; break;
	case FISH: cout << " (���) "; break;
	case BIRDS: cout << " (����) "; break;
	case UNKNOWN: cout << " (��Ȯ�� ����ü) "; break;
	}
	cout << this->age << "��" << endl;
}
