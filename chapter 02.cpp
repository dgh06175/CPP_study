#include <iostream>
using namespace std;

/* 62p [����2] */
//#include <stdlib.h>
//int main(void)
//{
//	int ary1[100] = { 0, };
//	int* ary2 = (int*)malloc(100 * sizeof(int)); // �޸� ����� ũ�⸦ �̸� �Ҵ�
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

/* 62p [����3] */
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
//	MyFunc(a1, b1); // ���� ���� ȣ��(Call by value)
//	MyFunc(&a2, &b2); // ������ ���� ȣ��(Call by reference)
//	cout << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
//}

/* 80p ���� 02-1 */
//void MyFunc1(int& n)
//{
//	n++;
//}
//
//void MyFunc2(int& n)
//{
//	n = -1 * n;
//}
//
//int main(void)
//{
//	int num1, num2;
//	num1 = 10;
//	num2 = 10;
//	MyFunc1(num1);
//	MyFunc2(num2);
//	cout << num1 << endl << num2;
//}

/* ����2 */
// ������ ������ ���޵Ǿ�� �ϴµ� �׳� ������ ���޵Ǹ� ������ ������ �����Ѵ�.

/* ���� 3 */
//void SwapPointer(int* a, int* b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main(void)
//{
//	int num1 = 5;
//	int* ptr1 = &num1;
//	int num2 = 10;
//	int* ptr2 = &num2;
//	SwapPointer(ptr1, ptr2);
//	cout << num1 << " " << num2;
//}

//int& RefRetFuncOne(int& ref)
//{
//	ref++;
//	return ref;
//}
//
//int main(void)
//{
//	int num1 = 1;
//	int num2 = RefRetFuncOne(num1);
//	num1 += 1;
//	num2 += 100;
//	cout << "num1: " << num1 << endl;
//	cout << "num2: " << num2 << endl;
//}

//int& RefRetFunc(int n)
//{
//	int num = 10;
//	num += n;
//	return num;
//}
//
//int main(void)
//{
//	int& b = RefRetFunc(6);
//	cout << b;
//}

//int Plus(int a, int b)
//{
//	return a + b;
//}
//int main(void)
//{
//	int a = 10;
//	const int& b = 5;
//	cout << Plus(a,10);
//}

/* p90 ���� 2 */
int main(void)
{
	const int num = 12;
	const int* ptr = &num;
	const int*& refptr = ptr;
	cout << *refptr << " " << *ptr;
}