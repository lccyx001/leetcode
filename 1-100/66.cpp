#include <vector>
#include <algorithm>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int carrier = 1;
    reverse(digits.begin(), digits.end());
    for (auto &i : digits)
    {
        if (i < 9)
        {
            i++;
            carrier = 0;
            break;
        }
        int tmp = i + carrier;
        i = (i + carrier) % 10;
        carrier = tmp / 10;
    }
    if (carrier > 0)
        digits.push_back(1);
    reverse(digits.begin(), digits.end());
    return digits;
}