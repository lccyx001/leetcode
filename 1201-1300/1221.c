/* 在一个「平衡字符串」中，'L' 和 'R' 字符的数量是相同的。
给出一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
返回可以通过分割得到的平衡字符串的最大数量。
示例 1：
输入：s = "RLRRLLRLRL"
输出：4
解释：s 可以分割为 "RL", "RRLL", "RL", "RL", 每个子字符串中都包含相同数量的 'L' 和 'R'。
示例 2：
输入：s = "RLLLLRRRLR"
输出：3
解释：s 可以分割为 "RL", "LLLRRR", "LR", 每个子字符串中都包含相同数量的 'L' 和 'R'。
示例 3：
输入：s = "LLLLRRRR"
输出：1
解释：s 只能保持原样 "LLLLRRRR".
提示：
1 <= s.length <= 1000
s[i] = 'L' 或 'R'
分割得到的每个字符串都必须是平衡字符串。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-a-string-in-balanced-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int balancedStringSplit(char *s)
{
    if (!s)
        return 0;
    int len = strlen(s), i = 0;
    int *diff = (int *)malloc(len * sizeof(int));
    memset(diff, 0, len * sizeof(int));
    int ptr = 0;
    while (i < len)
    {
        char c = s[i];
        int count = 0;
        while (i < len && c == s[i])
        {
            ++i;
            ++count;
        }
        diff[ptr++] = count;
    }

    int result = 0;
    for (int i = 1; i < ptr; i++)
    {
        if (diff[i] == diff[i - 1]||)
        {
            printf("%d,%d\n", diff[i - 1], diff[i]);
            diff[i] = diff[i] - diff[i - 1];
            ++result;
        }
    }
    return result;
}

int main()
{
    // char *a = "RLRRRLLRLL";
    char *a = "RRLRRLRLLLRL";

    int b = balancedStringSplit(a);
    // int c = a[2] == a[3];
    printf("%d", b);
}

// 无力吐槽了，是我理解能力有问题么？正确答案是下边
/* int balancedStringSplit(char * s){
    short i=0,count=0,sign=0;
    while(s[i]){
        sign=s[i++]=='L'?sign+1:sign-1;
        if(sign==0) count++;
    }
    return count;
}

作者：bevischou
链接：https://leetcode-cn.com/problems/split-a-string-in-balanced-strings/solution/cyu-yan-chang-gui-zuo-fa-by-bevischou-18/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */