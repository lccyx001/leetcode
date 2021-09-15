#include <string>
#include <iostream>
using namespace std;

string reverseVowels(string s)
{
    int n = s.size();
    string aeo = "aeiou";
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (aeo.find(tolower(s[i])) == string::npos)
        {
            i++;
            continue;
        }
        if (aeo.find(tolower(s[j])) == string::npos)
        {
            j--;
            continue;
        }
        swap(s[i], s[j]);
        i++;
        j--;
    }

    return s;
}

int main()
{
    string s = "hello";
    cout << reverseVowels(s) << endl;
}