#include <string>
using namespace std;
bool checkRecord(string s)
{
    int lctn = 0, actn = 0, n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            actn++;
        if (s[i] == 'L')
            lctn++;
        else
            lctn = 0;
        if (lctn >= 3 || actn >= 2)
            return false;
    }
    return true;
}