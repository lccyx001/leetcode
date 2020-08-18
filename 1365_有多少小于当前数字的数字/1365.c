/* 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。
示例 1：
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：
输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
提示：
2 <= nums.length <= 500
0 <= nums[i] <= 100 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    if (!nums || numsSize < 0)
        return NULL;

    int *result = (int *)malloc(numsSize * sizeof(int));
    if (!result)
        return NULL;
    memset(result,0,numsSize*sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (nums[j] < nums[i]&&i!=j)
                result[i]++;
        }
    }
    *returnSize = numsSize;
    return result;
}
// 桶排序，内存占用并没有增加多少
int x(int *nums, int numsSize, int *returnSize){
    // 比n^2快的桶排序
    int *bucket = calloc(sizeof(int), 101); //造一个桶
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i;
    //往桶里装东西
    for (i = 0; i < numsSize; i++)
    {
        bucket[nums[i]]++;
    }
    int sum = 0, j = 0;
    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < nums[i]; j++)
        {
            sum = sum + bucket[j];
        }
        ans[i] = sum;
        sum = 0;
    }
    return ans;
};

int main(){
    int a[]={8,1,2,2,3};
    // int* b = smallerNumbersThanCurrent(a,5,);
}