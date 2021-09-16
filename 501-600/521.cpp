#include <string>
using namespace std;

int findLUSlength(string a, string b)
{
    int na = a.size(), nb = b.size();
    if (na == nb && a.find(b) == string::npos)
        return na;
    else if (na == nb && a.find(b) != string::npos)
        return -1;
    else
        return na > nb ? na : nb;
}