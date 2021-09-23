#include <string>
using namespace std;
string reverseOnlyLetters(string s)
{
    int n = s.size();
    for (int i = 0, j = n - 1; i <= j;)
    {
        if (!isalpha(s[i]))
        {
            i++;
            continue;
        }
        if (!isalpha(s[j]))
        {
            j--;
            continue;
        }
        swap(s[i++], s[j++]);
    }
    return s;
}