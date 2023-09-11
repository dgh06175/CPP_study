#include <iostream>
using namespace std;
void name();
void me();
void sumInt(int, int);
void starPrint(int);

int main()
{
    name();
    cout << endl;
    me();
    cout << endl;
    sumInt(1, 10);
    cout << endl;
    starPrint(4);
    return 0;
}

void name()
{
    cout << "My name is Sang. \n";
}

void me()
{
    cout << "정보통신공학부" << endl
         << "25세" << endl
         << "SW개발자를 지망합니다." << endl;
}

void sumInt(int startNum, int endNum)
{
    int sum = 0;
    for (int i = startNum; i <= endNum; i++)
    {
        sum += i;
    }
    cout << startNum << "에서 " << endNum << "까지 더한 결과는 " << sum << "입니다." << endl;
}

void starPrint(int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}