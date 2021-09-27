#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    vector<int> ans;

    for (int i = 0, j = n - 1; i < j;)
    {
        if (numbers[i] + numbers[j] == target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }

        if (numbers[i] + numbers[j] < target)
            i++;
        else
            j--;
    }
    return ans;
}