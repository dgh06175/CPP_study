#pragma once
#include <iostream>
using namespace std;

template <typename Type>
class MyArray
{
private:
	Type* ary;
	int size;
public:
	MyArray() { ary = 0; size = 0; }		// ����Ʈ ������
	MyArray(int s);							// �����ε�� ������, ũŰs�� �迭�� �����Ҵ��Ѵ�.
	MyArray(const MyArray& br);				// ���� ������
	~MyArray() { delete[] ary; }			// �Ҹ���
	MyArray& operator = (const MyArray& br);// ���Կ�����
	bool put(int index, Type val);			// val�� ���� index�濡 ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
	bool get(int index, Type& getdata);		// �迭��� �� index���� ���� getdata�� ����.
											// ������true, ���н� false ��ȯ(ũ�⸦ �����)
	int getSize();							// �迭����� ���� Ȯ��
	Type* getAry(void);						// �迭����� ���� Ȯ��
};


template <typename Type>
MyArray<Type>::MyArray(int s)	// �����ε�� ������, ũŰs�� �迭�� �����Ҵ��Ѵ�.
{
	ary = new Type[s];
	size = s;
}

template <typename Type>
MyArray<Type>::MyArray(const MyArray& br)	// ���� ������
{
	this->ary = new Type[br.size];
	size = br.size;
	for (int i = 0; i < size; i++) {
		this->ary[i] = br.ary[i];
	}
}

template <typename Type>
MyArray<Type>& MyArray<Type>::operator = (const MyArray& br)// ���Կ�����
{
	if (this == &br)return *this;
	delete[]this->ary;
	this->ary = new Type[br.size];
	for (int i = 0; i < br.size; i++) {
		this->ary[i] = br.ary[i];
	}
	size = br.size;
	return *this;
}

template <typename Type>
bool MyArray<Type>::put(int index, Type val) // val�� ���� index�濡 ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
{
	if (index >= size || index < 0) { return false; }
	ary[index] = val;
	return true;
}

template <typename Type>
bool MyArray<Type>::get(int index, Type& getdata) // �迭��� �� index���� ���� getdata�� ����. ������true, ���н� false ��ȯ(ũ�⸦ �����)
{
	if (index >= size || index < 0) { return false; }
	getdata = ary[index];
	return true;
}

template <typename Type>
int MyArray<Type>::getSize() // �迭����� ���� Ȯ��
{
	return size;
}

template <typename Type>
Type* MyArray<Type>::getAry(void) // �迭����� ���� Ȯ��
{
	Type* tempAry = new Type[size];
	for (int i = 0; i < size; i++) {
		tempAry[i] = ary[i];
	}
	return tempAry;
}