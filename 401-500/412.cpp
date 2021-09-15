#include <vector>
#include <string>
using namespace std;
vector<string> fizzBuzz(int n)
{
    vector<string> v;
    for (int i = 1; i <= n; i++)
    {
        string s = "";
        if (i % 3 == 0)
            s += "Fizz";
        if (i % 5 == 0)
            s += "Buzz";
        if (i % 3 != 0 && i % 5 != 0)
            s += to_string(i);
        v.push_back(s);
    }
    return v;
}