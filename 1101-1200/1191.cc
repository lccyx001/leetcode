#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    vector<int> ans;
    for (int i = 0; i < k; i++)
        for (auto &a : arr)
            ans.push_back(a);
    int max_sumt = -10001, modd = int(pow(10, 9) + 7), tmp = 0;

    for (auto &a : ans)
    {
        tmp = max(tmp, (tmp + a) % modd);
        cout << tmp << endl;
        if (tmp > max_sumt)
            max_sumt = tmp;
    }

    return max_sumt;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(-2);
    arr.push_back(1);
    cout << kConcatenationMaxSum(arr, 5);
}