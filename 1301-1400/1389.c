/* 给你两个整数数组 nums 和 index。你需要按照以下规则创建目标数组：
目标数组 target 最初为空。
按从左到右的顺序依次读取 nums[i] 和 index[i]，在 target 数组中的下标 index[i] 处插入值 nums[i] 。
重复上一步，直到在 nums 和 index 中都没有要读取的元素。
请你返回目标数组。
题目保证数字插入位置总是存在。
示例 1：
输入：nums = [0,1,2,3,4], index = [0,1,2,2,1]
输出：[0,4,1,3,2]
解释：
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]
示例 2：
输入：nums = [1,2,3,4,0], index = [0,1,2,3,0]
输出：[0,1,2,3,4]
解释：5-0-1
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]
示例 3：
输入：nums = [1], index = [0]
输出：[1]
提示：
1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *createTargetArray(int *nums, int numsSize, int *index, int indexSize, int *returnSize)
{
    if (!nums || !index)
        return NULL;
    int *result = malloc(numsSize * sizeof(int));
    if (!result)
        return NULL;
    memset(result, -1, sizeof(int));
    int i = 0, n, movestep;
    int *tail;

    while (i < indexSize)
    {
        int t_idx = index[i];
        if (result[t_idx] == -1)
            result[t_idx] = nums[i];
        else
        {
            tail = result + numsSize - 1;
            movestep = numsSize - t_idx - 1;
            while (movestep-- > 0)
            {
                *tail = *(tail - 1);
                tail--;
            }
            *tail = nums[i];
        }
        i++;
    }
    *returnSize = numsSize;
    return result;
}

int main()
{
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {0, 1, 2, 2, 1};
    int *d = malloc(sizeof(int));
    int *c = createTargetArray(a, 5, b, 5, d);

    for (int i = 0; i < *d; i++)
    {
        printf("%d", c[i]);
    }
}
// ptr 操作会玩了移动数据还真是简单 ^_^