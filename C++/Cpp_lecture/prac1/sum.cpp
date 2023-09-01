#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int startNum = 1;
    int endNum = 10;
    for (int i = startNum; i <= endNum; i++)
    {
        sum += i;
    }
    cout << startNum << "에서 " << endNum << "까지 더한 결과는 " << sum << "입니다." << endl;
}