#pragma once
class MyArray
{
private:
	int* ary;
	int size;
public:
	MyArray() { ary = 0; size = 0; }		// 디폴트 생성자
	MyArray(int s);							// 오버로디드 생성자, 크키s의 배열을 동적할당한다.
	MyArray(const MyArray& br);				// 복사 생성자
	~MyArray() { delete[] ary; }			// 소멸자
	MyArray& operator = (const MyArray& br);// 대입연산자
	bool put(int index, int val);			// val의 값을 index방에 저장. 성공시true, 실패시 false 반환(크기를 벗어날때)
	bool get(int index, int& getdata);		// 배열요소 중 index방의 값을 getdata에 저장.
											// 성공시true, 실패시 false 반환(크기를 벗어날때)
	int getSize();							// 배열요소의 개수 확인
	int* getAry(void);						// 배열요소의 내용 확인
};