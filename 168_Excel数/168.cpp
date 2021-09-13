#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string convertToTitle(int columnNumber)
{
    string ans;
    while (columnNumber--)
    {
        ans += columnNumber % 26 + 'A';
        columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string ans = convertToTitle(52);
    cout << ans;
}
