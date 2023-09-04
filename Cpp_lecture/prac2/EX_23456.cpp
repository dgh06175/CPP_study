#include <iostream>
using namespace std;

void EX_2();
void EX_3();
void EX_4();
void EX_5();
void EX_6();
double biggest(double[], int);

int main()
{
    EX_2();
    EX_3();
    cin.ignore();
    EX_4();
    EX_5();
    cin.ignore();
    EX_6();
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
    cout << "새 암호를 입력하세요 >>";
    cin >> password1;
    cout << "새 암호를 다시 한번 입력하세요 >>";
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
    cin.getline(name, sizeof(name) / sizeof(*name));
    cout << "주소는? ";
    cin.getline(address, sizeof(address) / sizeof(*address));
    cout << "나이는? ";
    cin >> age;
    cout << "-------------------------------" << endl;
    cout << name << ". " << address << ". " << age << "세" << endl
         << endl;
}