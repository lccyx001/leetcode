#include <iostream>
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
// 父节点偷过，子节点就不能再偷了

struct SubtreeStatus
{
    int selected;
    int notSelected;
};

class Solution
{
public:
    SubtreeStatus dfs(TreeNode *node)
    {
        if (!node)
        {
            return {0, 0};
        }
        auto l = dfs(node->left);
        auto r = dfs(node->right);
        int selected = node->val + l.notSelected + r.notSelected;
        int notSelected = max(l.selected, l.notSelected) + max(r.selected, r.notSelected);
        return {selected, notSelected};
    }

    int rob(TreeNode *root)
    {
        auto rootStatus = dfs(root);
        return max(rootStatus.selected, rootStatus.notSelected);
    }
};

int main()
{
    vector<vector<int>> dp;
    dp.push_back(vector<int>());
    dp.push_back(vector<int>());
    dp[0].push_back(0);
    // dp[1][0] = 0;
}