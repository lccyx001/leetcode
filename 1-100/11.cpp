#include <vector>
using namespace std;
// int maxArea(vector<int> &height)
// {
//     int n = height.size();
//     int area = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (j <= i)
//                 continue;
//             int s = (j - i) * min(height[i], height[j]);
//             area = area > s ? area : s;
//         }
//     }
//     return area;
// }

// 暴力解法超时
int maxArea(vector<int> &height)
{
    int n = height.size();
    int i = 0, j = n - 1, s = 0;
    while (i < j)
    {
        int stmp = (j - i) * min(height[i], height[j]);
        s = stmp > s ? stmp : s;
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return s;
}