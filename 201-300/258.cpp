#include <iostream>
using namespace std;
int addDigits(int num)
{
    int buf;
    while (num > 9)
    {
        buf = 0;
        while (num > 0)
        {
            buf += num % 10;
            num /= 10;
        }
        num = buf;
    }

    return num;
}

int main()
{
    cout << addDigits(38);
}