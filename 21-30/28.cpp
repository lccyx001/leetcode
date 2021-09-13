#include <string>
#include <iostream>
using namespace std;
int strStr(string haystack, string needle)
{
    if (needle.size() == 0)
        return 0;
    int hsize = haystack.size(), nsize = needle.size();
    if (hsize < nsize)
        return -1;
    int pos = 0;

    while (pos < hsize - nsize + 1)
    {
        int step = 0;
        while (step < nsize)
        {
            if (haystack[pos + step] == needle[step])
                step++;
            else
                break;
        }
        if (step == nsize)
            return pos;
        pos++;
    }
    return -1;
}

int main()
{
    string a = "mississippi", b = "pi";
    int x = strStr(a, b);
    cout << x << endl;
}