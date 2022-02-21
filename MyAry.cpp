#include "MyAry.h"
#include <iostream>
using namespace std;

MyArray::MyArray(int s)	// �����ε�� ������, ũŰs�� �迭�� �����Ҵ��Ѵ�.
{
	ary = new int[s];
	size = s;
}
MyArray::MyArray(const MyArray& br)	// ���� ������
{
	this->ary = new int[br.size];
	size = br.size;
	for (int i = 0; i < size; i++) {
		this->ary[i] = br.ary[i];
	}
}

MyArray& MyArray::operator = (const MyArray& br)// ���Կ�����
{
	if (this == &br)return *this;
	delete[]this->ary;
	this->ary = new int[br.size];
	for (int i = 0; i < br.size; i++) {
		this->ary[i] = br.ary[i];
	}
	size = br.size;
	return *this;
}

bool MyArray::put(int index, int val) // val�� ���� index�濡 ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
{
	if (index >= size || index < 0) { return false; }
	ary[index] = val;
	return true;
}

bool MyArray::get(int index, int& getdata) // �迭��� �� index���� ���� getdata�� ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
{
	if (index >= size || index < 0) { return false; }
	getdata = ary[index];
	return true;
}

int MyArray::getSize() // �迭����� ���� Ȯ��
{
	return size;
}

int* MyArray::getAry(void) // �迭����� ���� Ȯ��
{
	int* tempAry = new int[size];
	for (int i = 0; i < size; i++) {
		tempAry[i] = ary[i];
	}
	return tempAry;
}