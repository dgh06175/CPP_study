#include <iostream>
using namespace std;

/*BetweenAdder*/
//int main(void)
//{
//	int s1, s2;
//	int result = 0;
//	std::cout << "두개의 정수를 입력하세요 : ";
//	std::cin >> s1 >> s2;
//	if (s1 < s2) {
//		for (int i = s1 + 1; i < s2; i++) result += i;
//	}
//	else
//	{
//		for (int i = s2 + 1; i < s1; i++) result += i;
//	}
//	std::cout << "두 정수 사이 값들의 합은 " << result << "입니다." << std::endl;
//	return 0;
//}

/*StringIO*/
//int main(void)
//{
//	char name[100];
//	char lang[100];
//	std::cout << "이름은 무엇입니까?";
//	std::cin >> name;
//
//	std::cout << "좋아하는 프로그래밍 언어는 무엇입니까?";
//	std::cin >> lang;
//	std::cout << "내 이름은 " << name << "입니다.\n좋아하는 프로그래밍 언어는 " << lang << "입니다." << std::endl;
//	return 0;
//}

/*전화번호부 저장 프로그램*/
//int main(void)
//{
//	char NumAry[5][100];
//	char NameAry[5][100];
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << i + 1 << "번째 사람의 이름을 입력하세요: ";
//		std::cin >> NameAry[i];
//		std::cout << i + 1 << "번째 사람의 번호를 입력하세요: ";
//		std::cin >> NumAry[i];
//		
//	}
//	std::cout << std::endl << "전화번호부" << std::endl;
//	for (int i = 0; i < 5; i++)
//	{
//		std::cout << NameAry[i] << " " << NumAry[i]<<std::endl;
//	}
//	return 0;
//}

/*구구단 출력 프로그램*/
//int main(void)
//{
//	int n;
//	std::cout << "구구단 몇단을 출력하시겠습니까? : ";
//	std::cin >> n;
//	for (int i = 1; i <= 9; i++)
//	{
//		std::cout << n << " * " << i << " = " << n * i << std::endl;
//	}
//}

/*판매원들의 급여 계산 프로그램*/
//int main(void)
//{
//	double n;
//	while (1)
//	{
//		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
//		std::cin >> n;
//		if (n == -1) {
//			std::cout << "프로그램을 종료합니다." << std::endl;
//			break;
//		}
//		std::cout << "이번 달 급여: " << 50.0 + n * 0.12 << "만원" << std::endl;
//	}
//}

/*함수 오버로딩*/
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

/*문자열 배열 테스트*/
//int main(void)
//{
//    char a[5][5] = { '1','2','3','4','\0','6','7','8','9','\0','1','2','3','4','\0','6','7','8','9','\0','1','2','3','4','\0' };
//    char b[5][5] = { "appl","bana","dede","ewda","osod" };
//    printf("%s ", a[1]);
//    printf("\n\n%d", b[1][4]);
//    printf("\n\n%c", 0);
//}

///*함수 오버로딩2*/
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

///*함수 매개변수 디폴트 값 DefalutValue*/
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
//		cout << "상현함수" << endl;
//	}
//}
//
//namespace HongSu
//{
//	void MyFunc(void)
//	{
//		cout << "수정함수";
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

/*namespace, inline함수*/
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

/*이름공간 같은공간에서의 호출(Bestcom)*/
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
//	cout << "BestCom에 정의된 함수" << endl;
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
//	cout << "ProgCom에 정의된 함수" << endl;
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