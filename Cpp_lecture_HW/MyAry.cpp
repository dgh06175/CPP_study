#include "MyAry.h"
#include <iostream>
using namespace std;

MyArray::MyArray(int s)	// 오버로디드 생성자, 크키s의 배열을 동적할당한다.
{
	ary = new int[s];
	size = s;
}
MyArray::MyArray(const MyArray& br)	// 복사 생성자
{
	this->ary = new int[br.size];
	size = br.size;
	for (int i = 0; i < size; i++) {
		this->ary[i] = br.ary[i];
	}
}

MyArray& MyArray::operator = (const MyArray& br)// 대입연산자
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

bool MyArray::put(int index, int val) // val의 값을 index방에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
{
	if (index >= size || index < 0) { return false; }
	ary[index] = val;
	return true;
}

bool MyArray::get(int index, int& getdata) // 배열요소 중 index방의 값을 getdata에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
{
	if (index >= size || index < 0) { return false; }
	getdata = ary[index];
	return true;
}

int MyArray::getSize() // 배열요소의 개수 확인
{
	return size;
}

int* MyArray::getAry(void) // 배열요소의 내용 확인
{
	int* tempAry = new int[size];
	for (int i = 0; i < size; i++) {
		tempAry[i] = ary[i];
	}
	return tempAry;
}