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

class CIRCLE
{
    int radius;

public:
    CIRCLE() { radius = 0; }
    CIRCLE(int r) { radius = r; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    float getArea() { return 3.14 * radius * radius; }
    ~CIRCLE() { radius = 0; }
};

void EX1020_1()
{
    CIRCLE cir[3] = {CIRCLE(10), CIRCLE(20), CIRCLE(30)};
    cir[0].setRadius(100);
    cir[1].setRadius(200);
    cir[2].setRadius(300);

    for (int i = 0; i < 3; i++)
    {
        cout << "면적: " << cir[i].getArea() << endl;
    }

    CIRCLE *p;
    p = cir;
    p++;
    p->setRadius(-100);
    (*p).setRadius(-500);

    p = cir;
    p[0].setRadius(-400);
    p[1].setRadius(-400);
    p[2].setRadius(-400);
    cout << (p + 2)->getArea() << endl;
}

class Color
{
    int red, green, blue;

public:
    Color() { red = green = blue = 0; }
    Color(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
    void setColor(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
    void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

void EX1020_2()
{
    Color screenColor(255, 0, 0); // 빨간색의 screenColor 객체 생성
    Color *p;                     // Color 타입의 포인터 변수 p 선언
    p = &screenColor;             // (1) p가 screenColor의 주소를 가지도록 코드 작성
    p->show();                    // (2) p와 show()를 이용하여 screenColor 색 출력
    Color colors[3];              // (3) Color의 일차원 배열 colors 선언. 원소는 3개
    p = colors;                   // (4) p가 colors 배열을 가리키도록 코드 작성
    // (5) p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
    // 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
    (p)->setColor(255, 0, 0);
    (p + 1)->setColor(0, 255, 0);
    (p + 2)->setColor(0, 0, 255);
    // (6) p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++)
    {
        colors[i].show();
    }
}

class allocTEST
{
public:
    int size;
    int *data;

public:
    allocTEST() { this->data = NULL; }
    allocTEST(int size_in)
    {
        data = new int[size_in];
        size = size_in;
    };
    ~allocTEST() { delete[] data; };
};

void EX1023_1()
{
    allocTEST E(100);
    for (int i = 0; i < E.size; i++)
    {
        cout << E.data[i] << " ";
    }
}

class Member
{
    string name;

public:
    Member() { name = ""; }
    Member(string name_in) { this->name = name_in; }
    string getName() { return name; }
    void setName(string name_in) { this->name = name_in; }
};

class Family
{
    string family_name;
    Member *p;
    int size;

public:
    Family(string name_in, int size_in);
    void setName(int index_in, string name_in);
    void show();
    ~Family();
};

Family::Family(string name_in, int size_in)
{
    this->family_name = name_in;
    this->size = size_in;
    p = new Member[size];
    if (p == NULL)
    {
        cout << "메모리 할당 실패";
    }
}

void Family::setName(int index_in, string name_in)
{
    p[index_in].setName(name_in);
}

void Family::show()
{
    cout << family_name << "가족은 다음과 같이 " << size << "명입니다." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << p[i].getName() << "  ";
    }
    cout << endl
         << endl;
}

Family::~Family(){};

void EX1023_2()
{
    Family simpson("Simpson", 3); // 3명으로 구성된 Simpson 가족
    simpson.setName(0, "Mr. Simpson");
    simpson.setName(1, "Mrs. Simpson");
    simpson.setName(2, "Bart Simpson");
    simpson.show();

    Family *kang = new Family("kang", 4); // 3명으로 구성된 Simpson 가족
    kang->setName(0, "Mr. kang");
    kang->setName(1, "Mrs. kang");
    kang->setName(2, "Bart kang");
    kang->setName(3, "kang's Dau");
    kang->show();
    delete kang;
}

class _Circle_
{
private:
    int radius;

public:
    _Circle_() { radius = 1; }
    _Circle_(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

void swapCircle(_Circle_ &A, _Circle_ *B)
{
    _Circle_ tmp;
    tmp = A;
    A = *B;
    *B = tmp;
}

void EX1030_1()
{
    _Circle_ A(2);
    _Circle_ B(3);

    cout << "A의 면적 = " << A.getArea() << " B의 면적 = " << B.getArea() << endl;

    swapCircle(A, &B);

    cout << "A의 면적 = " << A.getArea() << " B의 면적 = " << B.getArea() << endl;
}

void readRadius(_Circle_ &circle)
{
    int radius;
    cout << "정수 값으로 반지름을 입력하세요>>";
    cin >> radius;
    circle.setRadius(radius);
}

void EX1030_2()
{
    _Circle_ donut;
    readRadius(donut);
    cout << "donut의 면적 = " << donut.getArea() << endl;
}

class Accumulator
{
    int value;

public:
    Accumulator(int value);  // 매개변수 value로 멤버 value를 초기화한다.
    Accumulator &add(int n); // value에 n을 더해 값을 누적한다.
    int get();               // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value)
{
    this->value = value;
}

Accumulator &Accumulator::add(int n)
{
    this->value += n;
    return *this;
}

int Accumulator::get()
{
    return this->value;
}

void EX1030_3()
{
    Accumulator acc(10);
    acc.add(5).add(6).add(7);  // acc의 value 멤버가 28이 된다.
    cout << acc.get() << endl; // 28 출력
}

class Book
{
    char *title; // 제목 문자열
    int price;   // 가격
public:
    Book(char *title, int price)
    {
        this->title = title;
        this->price = price;
    }
    ~Book()
    {
        cout << title << "소멸" << endl;
    };
    void set(char *title, int price)
    {
        this->title = title;
        this->price = price;
    }
    void show() { cout << title << ' ' << price << "원" << endl; }
};

void EX1030_4()
{
    Book cpp((char *)"명품C++", 10000);
    Book java = cpp;
    java.set((char *)"명품자바", 12000);
    cpp.show();
    java.show();
}

class _Student_
{
    char *name;

public:
    _Student_() { name = NULL; }
    _Student_(char *name)
    {
        int length = strlen(name);
        this->name = new char[length + 1];
        strcpy(this->name, name);
    }
    _Student_(_Student_ &inputObj)
    {
        int length = strlen(inputObj.name);
        this->name = new char[length + 1];
        strcpy(this->name, inputObj.name);
    }

    ~_Student_()
    {
        // delete[] name;
    }
    void showName()
    {
        cout << "이름이: " << name << endl;
    }
    void setName(char *name)
    {
        int length = strlen(name);
        delete[] this->name;
        this->name = new char[length + 1];
        strcpy(this->name, name);
    }
};

void EX1030_5()
{
    _Student_ A((char *)"SANG"), B;
    B = A;
    B.showName();
    B.setName((char *)"LEE");
    B.showName();
    A.showName();
}

class Person
{ // Person 클래스 선언
    char *name;
    int id;

public:
    Person(int id, char *name); // 생성자
    ~Person();                  // 소멸자
    void changeName(char *name);
    void show() { cout << id << ',' << name << endl; }
};

Person::Person(int id, char *name)
{ // 생성자
    this->id = id;
    int len = strlen(name);         // name의 문자 개수
    this->name = new char[len + 1]; // name 문자열 공간 핟당
    strcpy(this->name, name);       // name에 문자열 복사
}

Person::~Person()
{                      // 소멸자
    if (name)          // 만일 name에 동적 할당된 배열이 있으면
        delete[] name; // 동적 할당 메모리 소멸
}

void Person::changeName(char *name)
{ // 이름 변경
    if (strlen(name) > strlen(this->name))
        return;
    strcpy(this->name, name);
}

void EX1103_1()
{
    Person father(1, (char *)"Kitae"); // (1) father 객체 생성
    Person daughter(father);           // (2) daughter 객체 복사 생성. 복사생성자호출
    cout << "daughter 객체 생성 직후 ----" << endl;
    father.show();                        // (3) father 객체 출력
    daughter.show();                      // (3) daughter 객체 출력
    daughter.changeName((char *)"Grace"); // (4) daughter의 이름을 "Grace"로 변경
    cout << "daughter 이름을 Grace로 변경한 후 ----" << endl;
    father.show();   // (5) father 객체 출력
    daughter.show(); // (5) daughter 객체 출력
                     // (6), (7) daughter, father 객체 소멸
}

class _Book_
{
    char *title;
    int price;

public:
    _Book_()
    {
        title = NULL;
        price = 0;
    }
    _Book_(char *title, int price)
    {
        int length = strlen(title);
        this->title = new char[length + 1];
        strcpy(this->title, title);
        this->price = price;
    }
    _Book_(_Book_ &inputObj)
    {
        int length = strlen(inputObj.title);
        this->title = new char[length + 1];
        strcpy(this->title, inputObj.title);
        this->price = inputObj.price;
    }

    ~_Book_()
    {
        delete[] title;
    }
    void showData()
    {
        cout << "이름: " << title;
        cout << " 가격: " << price << endl;
    }
    void settitle(char *title)
    {
        int length = strlen(title);
        delete[] this->title;
        this->title = new char[length + 1];
        strcpy(this->title, title);
    }
    void setprice(int price)
    {
        this->price = price;
    }
};

void EX1103_2()
{
    _Book_ A((char *)"A", 1000), B;
    B = A;
    B.showData();
    B.settitle((char *)"B");
    B.setprice(2000);
    B.showData();
    A.showData();
}

class Complex
{
    float re, im;

public:
    Complex() { re = im = 0; }
    Complex(float im, float re)
    {
        this->re = re;
        this->im = im;
    }
    Complex operator+(Complex in)
    {
        Complex tmp;
        tmp.re = this->re + in.re;
        tmp.im = this->im + in.im;
        return tmp;
    }
    Complex operator-(Complex in)
    {
        Complex tmp;
        tmp.re = this->re - in.re;
        tmp.im = this->im - in.im;
        return tmp;
    }
    Complex operator*(Complex in)
    {
        Complex tmp;
        float a = this->re;
        float b = this->im;
        float c = in.re;
        float d = in.im;
        tmp.re = a * c - b * d;
        tmp.im = b * c + a * d;
        return tmp;
    }
    Complex operator/(Complex in)
    {
        Complex tmp;
        float a = this->re;
        float b = this->im;
        float c = in.re;
        float d = in.im;
        tmp.re = (a * c + b * d) / (c * c + d * d);
        tmp.im = (b * c - a * d) / (c * c + d * d);
        return tmp;
    }
    void show()
    {
        cout.precision(5);
        if (im >= 0)
            cout << re << " + j" << im << endl;
        else
            cout << re << " - j" << -im << endl;
    }
};

class Cpx
{
public:
    float re, im;

    Cpx() { re = im = 0; }
    Cpx(float im, float re)
    {
        this->re = re;
        this->im = im;
    }
    friend Complex operator+(const Complex &A, const Cpx &B);
    void show()
    {
        cout.precision(5);
        if (im >= 0)
            cout << re << " + j" << im << endl;
        else
            cout << re << " - j" << -im << endl;
    }
};

Cpx operator+(Cpx A, Cpx B)
{
    Cpx tmp;
    tmp.re = A.re + B.re;
    tmp.im = A.im + B.im;
    return tmp;
}

void EX1110_1()
{
    Complex X(2, 3), Y(3, 4), Z;
    Z = X + Y;
    Z.show();
    Z = X - Y;
    Z.show();
    Z = X * Y;
    Z.show();
    Z = X / Y;
    Z.show();
}

void EX1110_2()
{
    Cpx X(1, 2), Y(2, 3), Z;
    Z = X + Y;
    Z.show();
}

class Book_
{
private:
    char *title;
    int price;
    int pages;

public:
    Book_()
    {
        title = NULL;
        price = 0;
        pages = 0;
    }
    Book_(char *title, int price, int pages)
    {
        int length = strlen(title);
        this->title = new char[length + 1];
        strcpy(this->title, title);
        this->price = price;
        this->pages = pages;
    }
    Book_(Book_ &inputObj)
    {
        int length = strlen(inputObj.title);
        this->title = new char[length + 1];
        strcpy(this->title, inputObj.title);
        this->price = inputObj.price;
        this->pages = inputObj.pages;
    }
    void show()
    {
        cout << "제목: " << title << "가격: " << price << "페이지: " << pages << endl;
    }

    ~Book_()
    {
        delete[] title;
    }

    friend bool operator==(Book_ &Book_, int price);
    friend bool operator==(Book_ &Book_, char *title);
    friend bool operator==(Book_ &Book_1, Book_ &Book_2);
    friend bool operator!(Book_ &Book);
};

bool operator==(Book_ &Book_, int price)
{
    return Book_.price == price;
}

bool operator==(Book_ &Book_, char *title)
{
    return strcmp(Book_.title, title) == 0;
}

bool operator==(Book_ &Book_1, Book_ &Book_2)
{
    return strcmp(Book_1.title, Book_2.title) == 0 && Book_1.price == Book_2.price && Book_1.pages == Book_2.pages;
}

bool operator!(Book_ &Book)
{
    return Book.price == 0;
}

void EX1113_1()
{
    Book_ a((char *)"명품 C++", 30000, 500), b((char *)"고품 C++", 30000, 500);
    // price 비교
    if (a == 30000)
        cout << "정가 30000원" << endl;
    // 책 title 비교
    if (a == (char *)"명품 C++")
        cout << "명품 C++ 입니다." << endl;
    // title, price, pages 모두 비교
    if (a == b)
        cout << "두 책이 같은 책입니다." << endl;
    else
        cout << "두 책이 다른 책입니다." << endl;

    Book_ book((char *)"벼룩시장", 0, 50); // 가격은 0
    if (!book)
    {
        cout << "공짜다" << endl;
    }
}

void EX1113_2()
{
    int m = 2, n = 3;
    vector<vector<int>> A(m, vector<int>(n, 1));
    int y = 3, x = 2;
    vector<vector<int>> B(y, vector<int>(x, 1));
    vector<vector<int>> C(m, vector<int>(x, 1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < y; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

class A
{
    int y;

public:
    A() { cout << "A생성자" << endl; }
    A(int y)
    {
        this->y = y;
        cout << "A생성자 y 받음" << endl;
    }
    ~A() { cout << "A소멸자" << endl; }
};

class B : public A
{
    int x;

public:
    B() { cout << "B생성자" << endl; }
    B(int x)
    {
        this->x = x;
        cout << "B생성자, x 받음" << endl;
    }
    ~B() { cout << "B소멸자" << endl; }
};

class C : public B
{
    C() { cout << "C생성자" << endl; }
    ~C() { cout << "C소멸자" << endl; }
};

void EX1117_0()
{
    B b(1);
}

class Circle_
{
private:
    int radius;

public:
    Circle_()
    {
        radius = 1;
    }
    Circle_(int radius)
    {
        this->radius = radius;
    }

    double getArea()
    {
        return 3.14 * radius * radius;
    }
    void setRadius(int radius)
    {
        this->radius = radius;
    }
    int getRadius()
    {
        return radius;
    }
};

class NamedCircle : public Circle_
{
private:
    string name;

public:
    NamedCircle()
    {
        name = "피자";
    }
    NamedCircle(int radius, string name)
    {
        setRadius(radius);
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    void show()
    {
        cout << "반지름이 " << getRadius() << "인 " + name << endl;
    }
};

void EX1117_1()
{
    NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
    waffle.show();
}

void EX1120_1()
{
    double maxArea = 0;
    string maxName;
    NamedCircle pizza[5];
    cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " >> ";
        int radius;
        string name;
        cin >> radius >> name;
        pizza[i] = NamedCircle(radius, name);
        if (pizza[i].getArea() > maxArea)
        {
            maxArea = pizza[i].getArea();
            maxName = pizza[i].getName();
        }
    }
    cout << "가장 면적이 큰 피자는 " << maxName << "입니다." << endl;
}

class BaseArray
{
private:
    int capacity; // 동적 할당된 메모리 용량
    int *mem;     // 정수 배열을 만들기 위한 메모리 포인터
protected:
    BaseArray(int capacity = 100)
    {
        this->capacity = capacity;
        mem = new int[capacity];
    }

    ~BaseArray()
    {
        delete[] mem;
    }

    void put(int index, int val)
    {
        mem[index] = val;
    }

    int get(int index)
    {
        return mem[index];
    }

    int getCapacity()
    {
        return capacity;
    }
};

class MyQueue : public BaseArray
{
    int size;

public:
    MyQueue(int cap = 100) : BaseArray(cap)
    {
        size = 0;
    }

    void enqueue(int n)
    {
        if (size >= getCapacity())
        {
            cout << "용량 초과" << endl;
            return;
        }
        put(size, n);
        size++;
    }

    int dequeue()
    {
        if (size <= 0)
        {
            cout << "사이즈 너무 작음" << endl;
            return -1000000;
        }
        int tmp = get(0);
        for (int i = 0; i < size - 1; i++)
        {
            put(i, get(i + 1));
        }
        size--;
        return tmp;
    }

    int capacity()
    {
        return getCapacity();
    }

    int length()
    {
        return size;
    }
};

void EX1114_1()
{
    MyQueue mQ(100);
    int n;
    cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        mQ.enqueue(n); // 큐에 삽입
    }
    cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
    cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
    while (mQ.length() != 0)
    {
        cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
    }
    cout << endl
         << "큐의 현재 크기 : " << mQ.length() << endl;
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
    // EX1016_2();
    // EX1020_1();
    // EX1020_2();
    // EX1023_1();
    // EX1023_2();
    // EX1030_1();
    // EX1030_2();
    // EX1030_3();
    // EX1030_4();
    // EX1030_5();
    // EX1103_1();
    // EX1103_2();
    // EX1110_1();
    // EX1110_2();
    // EX1113_1();
    // EX1113_2();
    // EX1117_0();
    // EX1117_1();
    // EX1120_1();
    EX1114_1();
}
