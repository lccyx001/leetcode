#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string addStrings(string num1, string num2)
{
    int carrier = 0, n1, n2, n, i = 0, sum;
    string ans;
    n1 = num1.size();
    n2 = num2.size();
    n = n1 > n2 ? n1 : n2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string num = n1 > n2 ? num1 : num2;

    while (i < n1 && i < n2)
    {
        sum = num1[i] - '0' + num2[i] - '0' + carrier;
        ans.push_back(sum % 10 + '0');
        carrier = sum / 10;
        i++;
    }

    while (i < n)
    {
        sum = num[i] - '0' + carrier;
        ans.push_back(sum % 10 + '0');
        carrier = sum / 10;
        i++;
    }
    if (carrier > 0)
        ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a = "99", b = "99";
    cout << addStrings(a, b);
}