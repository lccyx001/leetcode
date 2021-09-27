#include <math.h>
using namespace std;
int leastMinutes(int n)
{
    if (n == 1)
        return 1;
    for (int i = 1; i <= n; i++)
    {
        if (pow(2, i) >= n)
            return i;
    }
    return 0;
}