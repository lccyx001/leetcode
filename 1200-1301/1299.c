/* 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。
完成所有替换操作后，请你返回这个数组。
示例：
输入：arr = [17,18,5,4,6,1]
【18,18,5,4,6,1】
     
输出：[18,6,6,6,1,-1]
提示：
1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5
声明两个指针，former 和current，一个compare记录要比较的值
找值的过程former一直往后遍历，知道找到比current大的值，++ current 并将所有current的值换成former所指向的值
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <string.h>

int *replaceElements(int *arr, int arrSize, int *returnSize)
{
    if (arrSize == 0)
        return NULL;
    if (arrSize == 1)
    {
        *arr = -1;
        *returnSize = arrSize;
        return arr;
    }
    int *tail = arr + (arrSize - 1), compare, i = 0;
    compare = *tail;
    *(tail--) = -1;
    while (tail > arr)
    {
        if (compare < *tail)
        {
            int tmp = *tail;
            *tail = compare;
            compare = tmp;
            tail--;
        }
        else
        {
            *(tail--) = compare;
        }
    }
    *tail = compare;

    *returnSize = arrSize;
    return arr;
}

int main()
{
    int a[6] = {17, 18, 5, 4, 6, 1};
    int b = 0;
    int *c = replaceElements(a, 6, &b);
    int i = 0;
    while (i < b)
    {
        printf("%d", a[i]);
        i++;
    }
}
// 正的循环特别难写的时候，可以尝试逆向循环