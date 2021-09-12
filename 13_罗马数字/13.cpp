#include <string>
#include <iostream>
using namespace std;
int romanToInt(string s)
{
    int result = 0, n = s.size();

    for (int i = 0; i < n; i++)
    {

        if (s[i] == 'I')
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
                result -= 1;
            else
                result += 1;
        if (s[i] == 'V')
            result += 5;
        if (s[i] == 'X')
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
                result -= 10;
            else
                result += 10;
        if (s[i] == 'L')
            result += 50;

        if (s[i] == 'C')
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
                result -= 100;
            else
                result += 100;
        if (s[i] == 'D')
            result += 500;
        if (s[i] == 'M')
            result += 1000;
    }
    return result;
}

int main()
{
    string s = "MCMXCIV";
    int x;
    x = romanToInt(s);
    cout << x << endl;
}