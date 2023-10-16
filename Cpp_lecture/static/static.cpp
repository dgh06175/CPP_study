#include <iostream>
using namespace std;

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