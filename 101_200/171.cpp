#include <algorithm>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;
int titleToNumber(string columnTitle)
{
    reverse(columnTitle.begin(), columnTitle.end());
    int ans = 0, n = columnTitle.size();
    for (int i = 0; i < n; i++)
    {

        ans += (columnTitle[i] - 'A' + 1) * pow(26, i);
    }

    return ans;
}

int main()
{
    int a = titleToNumber("ZY");
    cout << a;
}