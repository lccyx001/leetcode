#include <iostream>
#include <set>
#include <math.h>
using namespace std;
bool isHappy(int n)
{
    bool ans = false;
    set<int> s;
    while (n != 1)
    {
        if (s.count(n))
        {
            break;
        }
        s.insert(n);
        n = next(n);
    }
    if (n == 1)
        ans = true;
    return ans;
}
int next(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += pow(n % 10, 2);
        n /= 10;
    }
    return ans;
}

int main()
{
    cout << next(19);
}