#include <string>
#include <iostream>
using namespace std;
bool rotateString(string s, string goal)
{
    return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    // if (s == goal)
    //     return true;
    // int n = s.size();
    // for (int i = 0; i < n; i++)
    // {
    //     string p = s.substr(i + 1, n - i) + s.substr(0, i + 1);
    //     if (p == goal)
    //         return true;
    // }
    // return false;
}

int main()
{
    string s = "abcde";
    cout << s + s << endl;
    string goal = "abced";
    cout << rotateString(s, goal);
}