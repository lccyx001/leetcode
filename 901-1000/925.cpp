#include <string>
#include <iostream>
using namespace std;
bool isLongPressedName(string name, string typed)
{
    int nn = name.size(), nt = typed.size();
    if (nn > nt)
        return false;
    int i = 0, j = 0;
    if (name[i] != typed[j])
        return false;

    while (i < nn && j < nt)
    {
        if (name[i] == typed[j])
        {
            i++;
            j++;
            continue;
        }

        while (name[i - 1] == typed[j])
            j++;
        if (name[i] != typed[j])
            return false;
    }

    while (j < nt)
        if (name[i - 1] != typed[j++])
            return false;
    return i == nn;
}

int main()
{

    string a = "leelee", b = "lleeelee";
    bool c = isLongPressedName(a, b);
    cout << c;
}