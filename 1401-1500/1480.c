#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// 给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。
// 请返回 nums 的动态和。

int* runningSum(int* nums, int numsSize, int* returnSize){
    if (nums == NULL || numsSize <= 0) {
        *returnSize  = 0;
        return NULL;
    }

    int *sum = (int *)malloc(numsSize * sizeof(int));
    if (sum == NULL) {
        // 内存不够返回空指针
        return NULL;
    }

    int k = 0;
    for (int i = 0; i < numsSize; ++i) {
        k += nums[i];
        sum[i] = k;
    }
    *returnSize = numsSize;
    return sum;
}

int main() {
    int a[10]={ 1, 2, 3,  4, 5, 6, 7,  8, 10, 9 };
    int rs= 0;
    int* sums;
    sums = runningSum(a, 10, &rs);
    for (int i=0;i< rs;i++){
        printf("%d:%d\n",i,sums[i]);
    }
}            