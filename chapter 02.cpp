#include <iostream>
#pragma	warning (disable:4996)
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
//int main(void)
//{
//	const int num = 12;
//	const int* ptr = &num;
//	const int*& refptr = ptr;
//	cout << *refptr << " " << *ptr;
//}

//#include <string.h>
//#include <stdlib.h>
//
//char* MakeStrAdr(int len)
//{
//	//char* str = (char*)malloc(sizeof(char) * len); // �� ������ �迭�� �Ҵ��Ѵ�.
//	char* str = new char[len];
//	return str;
//}
//
//int main(void)
//{
//	char* str = MakeStrAdr(20);
//	strcpy(str, "I am so happy~");
//	cout << str << endl;
//	//free(str); // ���� �Ҵ�� �޸� ������ �Ҹ��Ѵ�.
//	delete []str;
//}

//int main(void)
//{
//	int* p = new int;
//	int& b = *p;
//	b = 10;
//	cout << b << *p << a;
//}

//int main()
//{
//	int* ptr = new int;
//	int& ref = *ptr;
//	ref = 20;
//	cout << ref << *ptr;
//}

/* 95p ���� 02-3 */
//typedef struct __Point
//{
//	int xpos;
//	int ypos;
//}Point;
//
//Point& PntAdder(const Point& p1, const Point& p2)
//{
//	Point* sum = new Point;
//	sum->xpos = p1.xpos + p2.xpos;
//	sum->ypos = p1.ypos + p2.ypos;
//	return *sum;
//}
//
//int main(void)
//{
//	Point* ptr1 = new Point;
//	Point* ptr2 = new Point;
//	cout << "ù��° ���� ��ǥ�� �Է��ϼ���: ";
//	cin >> ptr1->xpos >> ptr1->ypos;
//	cout << "�ι�° ���� ��ǥ�� �Է��ϼ���: ";
//	cin >> ptr2->xpos >> ptr2->ypos;
//	Point& ptsum = PntAdder(*ptr1, *ptr2);
//	cout << "x��ǥ�� ��: " << ptsum.xpos << endl << "y��ǥ�� ��: " << ptsum.ypos;
//	delete ptr1;
//	delete ptr2;
//	delete &ptsum;
//}

/* 99p ���� 02-4-���� 1*/
//#include <cstring>
//
//int main(void)
//{
//	char* str = new char[20];
//	strcpy(str, "i am rich");
//	cout << str << endl << "���ڿ��� ���� : " << strlen(str) << endl;
//	char str2[20] = { 0, };
//	strcat(str2, str);
//	cout << "str2 : " << str2 << "\n���� ���� strcmp : " << strcmp(str, str2);
//}
/* ����2 */
//#include <cstdlib>
//#include <ctime>
//int main(void)
//{
//	srand((unsigned)time(NULL));
//	int random[5];
//	for (int i = 0; i < 5; i++)
//	{
//		random[i] = rand() % 100;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		cout << random[i] << endl;
//	}
//}