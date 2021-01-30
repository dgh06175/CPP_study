#include <iostream>
using namespace std;

/* 62p [문제2] */
//#include <stdlib.h>
//int main(void)
//{
//	int ary1[100] = { 0, };
//	int* ary2 = (int*)malloc(100 * sizeof(int)); // 메모리 블록의 크기를 미리 할당
//	for (int i = 0; i < 100; i++)
//	{
//		ary1[i] = i;
//		ary2[i] = i * 2;
//	}
//	for (int i = 0; i < 100; i++)
//	{
//		cout << ary1[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < 100; i++)
//	{
//		cout << ary2[i] << " ";
//	}
//}

/* 62p [문제3] */
//void MyFunc(int a, int b)
//{
//	a += 10;
//	b += 5;
//}
//
//void MyFunc(int *a, int *b)
//{
//	*a += 10;
//	*b += 5;
//}
//
//int main(void)
//{
//	int a1 = 2;
//	int b1 = 2;
//	int a2 = 4;
//	int b2 = 4;
//	MyFunc(a1, b1); // 값에 의한 호출(Call by value)
//	MyFunc(&a2, &b2); // 참조에 의한 호출(Call by reference)
//	cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
//}
