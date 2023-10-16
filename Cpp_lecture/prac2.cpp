#include <iostream>
using namespace std;

void EX_1();
void EX_2();
void EX_3();
void EX_4();
void EX_5();
void EX_6();
double biggest(double[], int);
int sum(int, int);

void EX_1()
{
    cout << "--------------EX1--------------" << endl;
    int n = 0;
    cout << "끝수를 입력하세요 >> ";
    cin >> n;
    if (n <= 0)
    {
        cout << "양수를 입력하세요 !\n";
        EX_1();
        return;
    }
    cout << "1에서 " << n << " 까지의 합은 " << sum(1, n) << " 입니다 \n\n";
}

int sum(int a, int b)
{
    int res = 0;
    for (int k = a; k <= b; k++)
    {
        res += k;
    }
    return res;
}

void EX_2()
{
    cout << "--------------EX2--------------" << endl;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            printf("%dX%d=%2d  ", i, j, i * j);
            // cout << i << "X" << j << "=" << i * j << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void EX_3()
{
    cout << "--------------EX3--------------" << endl;
    double a[5];
    cout << "5개의 실수를 입력하라>> ";

    for (int i = 0; i < 5; i++)
        cin >> a[i];
    cout << "제일 큰 수 = " << biggest(a, 5) << endl
         << endl;
}

double biggest(double ary[], int size)
{
    if (size < 1)
    {
        return 0.0;
    }

    double max = ary[0];
    for (int i = 0; i < size; i++)
    {
        if (ary[i] > max)
        {
            max = ary[i];
        }
    }
    return max;
}

void EX_4()
{
    cout << "--------------EX4--------------" << endl;
    char c[100];
    int count = 0;
    cout << "문자들을 입력하시오(100개 미만)" << endl;
    cin.ignore();
    cin.getline(c, sizeof(c) / sizeof(*c));
    for (int i = 0; i < 100; i++)
    {
        if (c[i] == 'x')
            count += 1;
    }
    cout << 'x' << "의 개수는 " << count << endl
         << endl;
}

void EX_5()
{
    cout << "--------------EX5--------------" << endl;
    char password1[100], password2[100];
    cout << "새 암호를 입력하세요 >> ";
    cin >> password1;
    cout << "새 암호를 다시 한번 입력하세요 >> ";
    cin >> password2;
    if (!strcmp(password1, password2))
    {
        cout << "같습니다." << endl
             << endl;
    }
    else
    {
        cout << "다릅니다." << endl
             << endl;
    }
}

void EX_6()
{
    cout << "--------------EX6--------------" << endl;
    char name[100], address[100];
    int age;

    cout << "이름은? ";
    cin.ignore();
    cin.getline(name, sizeof(name) / sizeof(*name));
    cout << "주소는? ";
    cin.ignore();
    cin.getline(address, sizeof(address) / sizeof(*address));
    cout << "나이는? ";
    cin >> age;
    cout << "-------------------------------" << endl;
    cout << name << ". " << address << ". " << age << "세\n\n";
}

void EX01911_1()
{
    int n = 10, m;
    char c = 'A';
    double d;

    int *p;
    p = &n;
    *p = 25;
    cout << n << endl;
}

void pointerTest0()
{
    cout << "포인터 값을 테스트 합니다.\n";
    float M[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << M << endl;
    cout << &M << endl;
    cout << &M[0] << endl;
    cout << *M << endl;
    cout << M + 1 << endl;
    cout << *(M + 1) << endl;
    cout << M[1] << endl;
    cout << *(M + 2) + 3 << endl;
}

void pointerTest1()
{
    cout << "포인터 테스트 1" << endl;
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *chr_ptr; // 1) int에 대한 포인터 변수 chr_ptr을 선언하는 문장 작성
    // chr_ptr이 arr 배열이 저장되어 있는 메모리 주소값을 갖도록 초기화.
    chr_ptr = &(arr[0]);
    chr_ptr++;                // chr_ptr의 값을 하나 증가
    cout << chr_ptr << "\n";  // 3) 옆 문장이 실행되었을 때의 결과는? [1]의 주소
    cout << *chr_ptr << "\n"; // 4) 옆 문장이 실행되었을 때의 결과는? 2
    cout << arr << "\n";      // 5) 옆 문장이 실행되었을 때의 결과는? arr의 주소
    cout << arr + 4 << "\n";  // 6) 옆 문장이 실행되었을 때의 결과는? arr[4]의 주소
    cout << &arr[3] << "\n";  // 7) 옆 문장이 실행되었을 때의 결과는? arr[3]의 주소
    cout << arr[4] << "\n";

    // arr[3]의 값을 chr_ptr을 이용하여 프린트
    cout << *chr_ptr + 2 << endl;
}

void pointerTest2()
{
    cout << "포인터 테스트 2" << endl;
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    int *ptr[5];
    ptr[0] = &a;
    ptr[1] = &b;
    ptr[2] = &c;
    ptr[3] = &d;
    ptr[4] = &d;

    for (int i = 0; i < sizeof(ptr) / sizeof(ptr[0]); i++)
    {
        cout << *ptr[i] << endl;
    }
}

void pointerTest3()
{
    cout << "포인터 테스트 3" << endl;
    int arr_0_[3] = {1, 2, 3};
    int arr_1_[4] = {11, 12, 13, 14};
    int arr_2_[5] = {21, 22, 23, 24, 25};
    int *ptr[3] = {arr_0_, arr_1_, arr_2_};
    cout << *(ptr[0] + 1) << " " << ptr[0][1] << endl; // 2 2
    cout << *(ptr[1] + 2) << " " << ptr[1][2] << endl; // 13 13
}

void FuncArray(int *ptr)
{
    cout << "FUNC " << ptr << endl;
    cout << "FUNC " << *ptr << endl;
    cout << "FUNC " << ptr[0] << endl;

    for (int i = 0; i < 5; i++)
    {
        *(ptr + i) = *(ptr + i) + 5;
    }
}

void pointerTest4()
{
    int c[5] = {10, 20, 30, 40, 50};
    cout << c << endl;
    cout << *c << endl;
    cout << c + 1 << endl;
    cout << *(c + 1) << endl;
    FuncArray(c);

    for (int i = 0; i < 5; i++)
    {
        cout << c[i] << endl;
    }
}

void swap(int &aa, int &bb)
{
    int tmp = aa;
    aa = bb;
    bb = tmp;
}

void Adder(int a, int b, int &c)
{
    c = a + b;
    cout << "PTR_reference FUNCTION" << endl;
}

void Adder(int a, int b, int *c)
{
    *c = a + b;
    cout << "PTR_pointer FUNCTION" << endl;
}

void AddSub(int a, int b, int &sum, int &diff)
{
    sum = a + b;
    diff = a - b;
    cout << "AddSub FUNCTION" << endl;
}

void referenceTest1()
{
    int target = 20;
    int &nickname = target;

    int a = 10, b = 20;
    swap(a, b);
    cout << a << b << endl;

    int c = 0;
    Adder(a, b, c);
    cout << "c: " << c << endl;

    c = 0;
    Adder(a, b, &c);
    cout << "c: " << c << endl;

    c = 0;
    int d = 0;
    AddSub(a, b, c, d);
    cout << "sum: " << c << "  diff: " << d << endl;
}

void EX0915_2_1()
{
    int M[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int(*ptr)[3];
    int *p;
    int **pt;
    ptr = M;
    cout << "ptr은 포인터 변수가 3개 들어갈수있는 배열이다 : " << ptr << "\nM은 이차원 배열 M의 첫 주소이다 : " << M << endl;
    cout << "ptr + 1은 ptr 포인터 변수의 두번쨰 배열의 주소이다 : " << ptr + 1 << "\n"
         << "M + 1은 M 이차원 배열의 두번쨰 배열의 주소이다 : " << M + 1 << endl;
    cout << "*(ptr + 1): " << *(ptr + 1) << "\nptr[1]: " << ptr[1] << "\n*(M + 1): " << *(M + 1) << "\nM[1]: " << M[1] << endl;
    cout << "\n**(ptr + 1): "
         << **(ptr + 1) << "\n"
         << "\n**(M + 1): "
         << **(M + 1) << "\n*M[1]: "
         << *M[1] << "\nM[1][0]: "
         << M[1][0] << endl;
    p = M[0];
    cout << "p: " << p << "\nM[0]: " << M[0] << "\n*M: " << *M << endl;
    cout << "p + 1: " << p + 1 << "\nM[0] + 1: " << M[0] + 1 << "\n*M + 1: " << *M + 1 << endl;
    cout << "*(p + 1): " << *(p + 1) << "\n(M[0] + 1): " << *(M[0] + 1) << "\n*(M + 1): " << *(*M + 1) << endl;
    pt = &p; // pt = M; (X)
    cout << "*pt: " << *pt << "\np: " << p << endl;
    cout << "**pt: " << **pt << "\n*p: " << *p << endl;
}

bool average(int a[], int size, float &avg)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    avg = (float)sum / size;
    return true;
}

void functest()
{
    int x[] = {0, 1, 2, 3, 4, 5};
    float avg;
    if (average(x, 6, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개 변수 오류" << endl;
}

void stringTest()
{
    string name;
    string address("서울시 성북구 삼성동 389");
    string copyAddres(address);

    char text[] = {'L', 'O', 'V', 'E', ' ', 'C', '+', '\0'};
    string title(text);

    cin >> name;
    cout << name << endl;
    cout << address << endl;
    cout << copyAddres << endl;
    cout << text << endl;
    cout << title.size() << endl;
    cout << (title == "LOVE CD+") << endl;
}

void vectorTest()
{
    vector<int> A = {3, 2};
    A.push_back(42);
    A.push_back(2);
    A.push_back(9);
    A.pop_back();
    for (int i = 0; i < A.size(); i++)
    {
        cout << A.at(i) << " ";
    }
    cout << endl;
    cout << A.size() << endl;
}

class Circle
{
private:
    int radius;

public:
    double getArea()
    {
        return (3.14 * radius * radius);
    }
    void setRadius(int r)
    {
        radius = r;
    }
};

void classTest()
{
    Circle donut;
    donut.setRadius(8);
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;

    Circle pizza;
    pizza.setRadius(30);
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;

    Circle *ptr;
    ptr = &pizza;

    cout << ptr->getArea() << endl;
}

void stringTest2()
{
    string names[5];

    for (int i = 0; i < 5; i++)
    {
        getline(cin, names[i]);
    }

    string lastString = names[0];
    for (int i = 1; i < 5; i++)
    {
        if (names[i] > lastString)
        {
            lastString = names[i];
        }
    }
    cout << lastString << endl;
}

class Rectangle
{
    double width;
    double height;

public:
    void setSize(double width, double height)
    {
        this->width = width;
        this->height = height;
    }

    double getArea()
    {
        return width * height;
    }
};

void classTest1()
{
    Rectangle rect;
    rect.setSize(3, 5);
    cout << "사각형의 면적은 " << rect.getArea() << endl;
}

class Circle0925
{
public:
    int radius;
    int *MEM;
    Circle0925();      // 생성자
    Circle0925(int r); // 생성자
    ~Circle0925();

    double getArea();
};
Circle0925::~Circle0925()
{
    delete[] MEM;
    cout << "반지름" << radius << "인 원 소멸" << endl;
}
Circle0925::Circle0925()
{
    MEM = new int[10000 * 10000];
    radius = 1;
    cout << "반지름" << radius << " 원 생성" << endl;
}
Circle0925::Circle0925(int r)
{
    MEM = new int[1410065408];
    radius = r;
    cout << "반지름" << radius << " 원 생성" << endl;
}
double Circle0925::getArea()
{
    return (3.14 * radius * radius);
}
// Circle0925 A(1000);
// Circle0925 B(2000);
int FFF()
{
    Circle0925 A(100);
    Circle0925 B(200);
    int a;
    cin >> a;
    return 0;
}

void classTest2()
{
    Circle0925 A, B(100), C(211);
    cout << C.getArea() << endl;
    FFF();
}

class Oval
{
    int width, height;

public:
    Oval(int width = 1, int height = 1);
    ~Oval();
    int getWidth();
    int getHeight();
    void set(int width, int height);
    void show();
};

Oval::Oval(int width, int height)
{
    this->width = width;
    this->height = height;
}

Oval::~Oval()
{
    cout << "Oval 소멸: "
         << "width: " << width << ", height: " << height << endl;
}

int Oval::getHeight()
{
    return height;
}

int Oval::getWidth()
{
    return width;
}

void Oval::set(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Oval::show()
{
    cout << "width: " << width << ", height: " << height << endl;
}

void EX0925_2()
{
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << ", " << b.getHeight() << endl;
}

class Rectangle0925
{
    double width;
    double height;

public:
    Rectangle0925(int size = 1);
    Rectangle0925(int width, int height);
    ~Rectangle0925();
    bool isSquare();
};

Rectangle0925::Rectangle0925(int size)
{
    width = size;
    height = size;
}
Rectangle0925::Rectangle0925(int width, int height)
{
    this->width = width;
    this->height = height;
}
bool Rectangle0925::isSquare()
{
    return width == height;
}
Rectangle0925::~Rectangle0925()
{
    cout << "width: " << width << ", height: " << height << "인 사각형 소멸" << endl;
}

void EX0925_1()
{
    Rectangle0925 rect1;
    Rectangle0925 rect2(3, 5);
    Rectangle0925 rect3(3);
    if (rect1.isSquare())
        cout << "rect1은 정사각형이다." << endl;
    if (rect2.isSquare())
        cout << "rect2는 정사각형이다." << endl;
    if (rect3.isSquare())
        cout << "rect3는 정사각형이다." << endl;
}

class Math
{
public:
    static int sh_abs(int a)
    {
        return a > 0 ? a : -a;
    }
    static int sh_max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    static int sh_min(int a, int b)
    {
        return (a > b) ? b : a;
    }
};

void EX1016()
{
    cout << Math::sh_abs(-5) << endl;
    cout << Math::sh_max(10, 8) << endl;
    cout << Math::sh_min(-3, -8) << endl;
}

class PERSON
{
public:
    int money;
    static int sharedMoney;

    string name;

    PERSON()
    {
        money = 0;
    }

    PERSON(string name_in)
    {
        money = 0;
        this->name = name_in;
    }

    ~PERSON()
    {
        cout << "name: " << name << ", money: " << money << endl; // 쉼표를 추가하여 출력을 명확하게 합니다.
    }

    void addMoney(int money_in)
    {
        money += money_in;
    }

    static void addShared(int money_in) // 정적 메서드로 선언
    {
        sharedMoney += money_in;
    }
};

int PERSON::sharedMoney = 0;

int EX1016_2()
{
    PERSON C = PERSON("JO");
    PERSON A("KANG"), B("KIM");
    // 3월
    A.addMoney(100);
    A.addShared(5);
    B.addMoney(200);
    B.addShared(5);
    // 4월
    A.addMoney(100);
    A.addShared(5);
    B.addMoney(200);
    B.addShared(5);
    cout << "공금 = " << PERSON::sharedMoney << endl;
    PERSON::addShared(100); // 이제 정상적으로 작동합니다.
    cout << "공금 = " << PERSON::sharedMoney << endl;
    return 0;
}

int main()
{
    // EX_1();
    // EX_2();
    // EX_3();
    // EX_4();
    // EX_5();
    // EX_6();
    // EX01911_1();
    // pointerTest0();
    // pointerTest1();
    // pointerTest2();
    // pointerTest3();
    // pointerTest4();
    // referenceTest1();
    // EX0915_2_1();
    // functest();
    // stringTest();
    // vectorTest();
    // classTest();
    // stringTest2();
    // classTest1();
    // classTest2();
    // EX0925_1();
    // EX0925_2();
    // EX1016();
    EX1016_2();
}
