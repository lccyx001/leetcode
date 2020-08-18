/* 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。

示例:
给定有序数组: [-10,-3,0,5,9, 11],

一个可能的答案是：[0,-3,9,-10,null,5,11]，它可以表示下面这个高度平衡二叉搜索树：

          0 
         / \ 
       -3   9 
       /   / \
     -10  5  11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-tree-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <stdio.h>
#include <stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (!nums || numsSize <= 0)
        return NULL;
    if (numsSize == 1)
    {
        struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val = nums[0];
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (!root)
        return NULL;
    // {-10, -3, 0, 5, 9, 10};
    int mid_idx = numsSize / 2;
    root->val = nums[mid_idx]; //1 2 3 4
    root->left = sortedArrayToBST(nums, mid_idx);
    if (mid_idx + 1 == numsSize)
    {
        // 到数组尾了
        root->right = NULL;
        return root;
    }
    int *bi_nums = nums;
    bi_nums += mid_idx + 1;
    // bi_nums += mid_idx + 1;
    root->right = sortedArrayToBST(bi_nums, numsSize - mid_idx - 1);
    return root;
}

int main()
{
    int a[] = {-10, -3, 0, 5, 9};
    struct TreeNode *b = sortedArrayToBST(a, 5);

    printf("%d\n", b->val);
    printf("%d\n", b->left->val);
    printf("%d\n", b->left->left->val);
    printf("%d\n", b->right->val);
    printf("%d\n", b->right->left->val);
}