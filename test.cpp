#include <iostream>
using namespace std;

/*BetweenAdder*/
//int main(void)
//{
//	int s1, s2;
//	int result = 0;
//	std::cout << "�ΰ��� ������ �Է��ϼ��� : ";
//	std::cin >> s1 >> s2;
//	if (s1 < s2) {
//		for (int i = s1 + 1; i < s2; i++) result += i;
//	}
//	else
//	{
//		for (int i = s2 + 1; i < s1; i++) result += i;
//	}
//	std::cout << "�� ���� ���� ������ ���� " << result << "�Դϴ�." << std::endl;
//	return 0;
//}

/*StringIO*/
//int main(void)
//{
//	char name[100];
//	char lang[100];
//	std::cout << "�̸��� �����Դϱ�?";
//	std::cin >> name;
//
//	std::cout << "�����ϴ� ���α׷��� ���� �����Դϱ�?";
//	std::cin >> lang;
//	std::cout << "�� �̸��� " << name << "�Դϴ�.\n�����ϴ� ���α׷��� ���� " << lang << "�Դϴ�." << std::endl;
//	return 0;
//}

/*��ȭ��ȣ�� ���� ���α׷�*/
//int main(void)
//{
//	char NumAry[5][100];
//	char NameAry[5][100];
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << i + 1 << "��° ����� �̸��� �Է��ϼ���: ";
//		std::cin >> NameAry[i];
//		std::cout << i + 1 << "��° ����� ��ȣ�� �Է��ϼ���: ";
//		std::cin >> NumAry[i];
//		
//	}
//	std::cout << std::endl << "��ȭ��ȣ��" << std::endl;
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << NameAry[i] << " " << NumAry[i]<<std::endl;
//	}
//	return 0;
//}

/*������ ��� ���α׷�*/
//int main(void)
//{
//	int n;
//	std::cout << "������ ����� ����Ͻðڽ��ϱ�? : ";
//	std::cin >> n;
//	for (int i = 1; i <= 9; i++)
//	{
//		std::cout << n << " * " << i << " = " << n * i << std::endl;
//	}
//}

/*�Ǹſ����� �޿� ��� ���α׷�*/
//int main(void)
//{
//	double n;
//	while (1)
//	{
//		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
//		std::cin >> n;
//		if (n == -1) {
//			std::cout << "���α׷��� �����մϴ�." << std::endl;
//			break;
//		}
//		std::cout << "�̹� �� �޿�: " << 50.0 + n * 0.12 << "����" << std::endl;
//	}
//}

/*�Լ� �����ε�*/
//int MyFunc(int num)
//{
//	return ++num;
//}
//int MyFunc(int a, int b)
//{
//	return a + b;
//}
//void MyFunc(char a)
//{
//	std::cout << a;
//}
//int main(void)
//{
//	std::cout << MyFunc(3) << std::endl << MyFunc(4, 8) << std::endl;
//	MyFunc('H');
//}

/*���ڿ� �迭 �׽�Ʈ*/
//int main(void)
//{
//    char a[5][5] = { '1','2','3','4','\0','6','7','8','9','\0','1','2','3','4','\0','6','7','8','9','\0','1','2','3','4','\0' };
//    char b[5][5] = { "appl","bana","dede","ewda","osod" };
//    printf("%s ", a[1]);
//    printf("\n\n%d", b[1][4]);
//    printf("\n\n%c", 0);
//}

///*�Լ� �����ε�2*/
//void swap(int *a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void swap(char* a, char* b)
//{
//	char temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void swap(double* a, double* b)
//{
//	double temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//int main(void)
//{
//	int num1 = 20, num2 = 30;
//	swap(&num1, &num2);
//	cout << num1 << ' ' << num2 << endl;
//
//	char ch1 = 'A', ch2 = 'Z';
//	swap(&ch1, &ch2);
//	cout << ch1 << ' ' << ch2 << endl;
//
//	double dbl1 = 1.111, dbl2 = 5.555;
//	swap(&dbl1, &dbl2);
//	cout << dbl1 << ' ' << dbl2 << endl;
//	return 0;
//}

///*�Լ� �Ű����� ����Ʈ �� DefalutValue*/
//int MyFunc(int n1, int n2 = 7, int n3 = 3)
//{
//	return n1 + n2 + n3;
//}
//
//int main()
//{
//	cout << MyFunc(5, 6);
//}

///*DefalutValue3*/
//int BoxVolume(int length, int width, int height);
//int BoxVolume(int length, int width);
//int BoxVolume(int length);
//int BoxVolume();
//
//int main()
//{
//	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
//	cout << "[5, 5, D] : " << BoxVolume(5, 5) << endl;
//	cout << "[7, D, D] : " << BoxVolume(7) << endl;
//	cout << "[D, D, D] : " << BoxVolume() << endl;
//	return 0;
//}
//
//int BoxVolume(int length, int width, int height)
//{
//	return length * width * height;
//}
//
//int BoxVolume(int length, int width)
//{
//	return length * width;
//}
//
//int BoxVolume(int length)
//{
//	return length;
//}
//
//int BoxVolume(void)
//{
//	return 999;
//}

/*namespace*/
//namespace LeeSang
//{
//	void MyFunc(void)
//	{
//		cout << "�����Լ�" << endl;
//	}
//}
//
//namespace HongSu
//{
//	void MyFunc(void)
//	{
//		cout << "�����Լ�";
//	}
//}
//
//namespace MYstd
//{
//	void cout(const char* string)
//	{
//		printf("%s", string);
//	}
//}
//
//int main()
//{
//	LeeSang::MyFunc();
//	HongSu::MyFunc();
//	MYstd::cout("hi");
//}

/*namespace, inline�Լ�*/
//#define square(x) (x*x)
//namespace sang
//{
//	inline int Xsquare(int x)
//	{
//		int a = x * x;
//		return a;
//	}
//
//	inline int MAXNUM(void)
//	{
//		return 8;
//	}
//
//	int Fsquare(int x)
//	{
//		return x * x;
//	}
//}
//
//int main()
//{
//	cout << square(8) << endl << sang::Xsquare(8) << endl << sang::Fsquare(8);
//
//}

/*�̸����� �������������� ȣ��(Bestcom)*/
//namespace BestCom
//{
//	void SimpleFunc(void);
//	void Func(void);
//}
//
//namespace ProgCom
//{
//	void SimpleFunc(void);
//}
//
//int main()
//{
//	BestCom::SimpleFunc();
//	ProgCom::SimpleFunc();
//}
//
//void BestCom::SimpleFunc(void)
//{
//	cout << "BestCom�� ���ǵ� �Լ�" << endl;
//	BestCom::Func();
//}
//
//void BestCom::Func(void)
//{
//	cout << "hii" << endl;
//}
//
//void ProgCom::SimpleFunc(void)
//{
//	cout << "ProgCom�� ���ǵ� �Լ�" << endl;
//}

//int a = 10;
//int main()
//{
//	int a = 5;
//	cout << ++a << endl;
//	cout << ++::a << endl;
//}

int main(void)
{
	cout << "hi";
}