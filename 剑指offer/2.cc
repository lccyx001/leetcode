#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string addBinary(string a, string b)
{

    int n = a.size(), m = b.size(), i = 0, j = 0, carrier = 0, p;
    if (n == 0 || m == 0)
        return a + b;
    string ans;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while (i < n && j < m)
    {
        p = a[i] - '0' + b[j] - '0' + carrier;
        carrier = p / 2;
        ans += to_string(p % 2);
        i++;
        j++;
    }
    while (i < n)
    {
        p = a[i] - '0' + carrier;
        carrier = p / 2;
        ans += to_string(p % 2);
        i++;
    }
    while (j < m)
    {
        p = b[j] - '0' + carrier;
        carrier = p / 2;
        ans += to_string(p % 2);
        j++;
    }

    if (carrier > 0)
        ans += to_string(carrier);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "11", b = "10";
    addBinary(a, b);
}