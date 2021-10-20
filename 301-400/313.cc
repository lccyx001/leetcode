#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int nthSuperUglyNumber(int n, vector<int> &primes)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;

    int m = primes.size();
    vector<int> pointers(m, 0);
    vector<int> nums(m, 1);

    for (int i = 1; i <= n; i++)
    {

        int minnum = INT32_MAX;
        for (int j = 0; j < m; j++)
        {
            minnum = min(minnum, nums[j]);
        }
        dp[i] = minnum;
        for (int j = 0; j < m; j++)
        {
            if (nums[j] == minnum)
            {
                pointers[j]++;
                nums[j] = dp[pointers[j]] * primes[j];
            }
        }
    }
    return dp[n];
}

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(13);
    a.push_back(19);
    cout << nthSuperUglyNumber(12, a);
}