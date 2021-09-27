#include <bitset>
using namespace std;

class Solution
{
public:
    int reverseBits(int num)
    {
        bitset<32> bst(num);
        int cnt1 = 0, cnt2 = 0; //cnt1表示前一段1，cnt2表示后一段1
        bool flag = false;      //flag表示后一段1是否可以和前一段1相连
        int ans = 1;            //记录答案
        int i = 0;              //记录遍历情况
        while (i < 32)
        {
            cnt2 = 0;
            while (i < 32 && bst[i])
            {
                ++i;
                ++cnt2; //记录后一段1的长度
            }
            ans = max(ans, flag ? (cnt1 + cnt2 + 1) : (cnt2 + 1)); //更新答案
            cnt1 = cnt2;                                           //后一段1变成前一段1，向后遍历
            cnt2 = 0;
            while (i < 32 && !bst[i])
            { //记录0的长度
                ++i;
                ++cnt2;
            }
            flag = cnt2 == 1; //如果0的长度为1，则可以连接
        }
        return min(ans, 32);
    }
};
