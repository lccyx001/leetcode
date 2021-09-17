#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void binaryForm(vector<int> &nums, TreeNode *root)
{
    int n = nums.size();
    if (n == 0)
        return;
    vector<int> lv, rv;
    for (int i = 0; i < n; i++)
    {
        if (i < n >> 1)
            lv.push_back(nums[i]);
        else if (i == n >> 1)
            continue;
        else
            rv.push_back(nums[i]);
    }
    root->val = nums[n >> 1];
    if (lv.size() > 0)
    {
        root->left = new TreeNode();
        binaryForm(lv, root->left);
    }

    if (rv.size() > 0)
    {
        root->right = new TreeNode();
        binaryForm(rv, root->right);
    }
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    TreeNode *root = new TreeNode();
    binaryForm(nums, root);
}