#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void reverseString(vector<char> &s)
{
    // reverse(s.begin(), s.end());
    int n = s.size();
    char x;
    for (int i = 0; i < n / 2; i++)
    {
        x = s[i];
        s[i] = s[n - i];
        s[n - i] = x;
    }
}