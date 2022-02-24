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
	MyArray() { ary = 0; size = 0; }		// 디폴트 생성자
	MyArray(int s);							// 오버로디드 생성자, 크키s의 배열을 동적할당한다.
	MyArray(const MyArray& br);				// 복사 생성자
	~MyArray() { delete[] ary; }			// 소멸자
	MyArray& operator = (const MyArray& br);// 대입연산자
	bool put(int index, Type val);			// val의 값을 index방에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
	bool get(int index, Type& getdata);		// 배열요소 중 index방의 값을 getdata에 저장.
											// 성공시true, 실패시 false 반환(크기를 벗어날때)
	int getSize();							// 배열요소의 개수 확인
	Type* getAry(void);						// 배열요소의 내용 확인
};


template <typename Type>
MyArray<Type>::MyArray(int s)	// 오버로디드 생성자, 크키s의 배열을 동적할당한다.
{
	ary = new Type[s];
	size = s;
}

template <typename Type>
MyArray<Type>::MyArray(const MyArray& br)	// 복사 생성자
{
	this->ary = new Type[br.size];
	size = br.size;
	for (int i = 0; i < size; i++) {
		this->ary[i] = br.ary[i];
	}
}

template <typename Type>
MyArray<Type>& MyArray<Type>::operator = (const MyArray& br)// 대입연산자
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
bool MyArray<Type>::put(int index, Type val) // val의 값을 index방에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
{
	if (index >= size || index < 0) { return false; }
	ary[index] = val;
	return true;
}

template <typename Type>
bool MyArray<Type>::get(int index, Type& getdata) // 배열요소 중 index방의 값을 getdata에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
{
	if (index >= size || index < 0) { return false; }
	getdata = ary[index];
	return true;
}

template <typename Type>
int MyArray<Type>::getSize() // 배열요소의 개수 확인
{
	return size;
}

template <typename Type>
Type* MyArray<Type>::getAry(void) // 배열요소의 내용 확인
{
	Type* tempAry = new Type[size];
	for (int i = 0; i < size; i++) {
		tempAry[i] = ary[i];
	}
	return tempAry;
}