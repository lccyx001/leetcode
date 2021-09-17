struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *root, int &s)
{
    if (!root)
        return;
    if (root->left && !root->left->left && root->left->right)
        s += root->left->val;
    dfs(root->left, s);
    dfs(root->right, s);
}

int sumOfLeftLeaves(TreeNode *root)
{
    int s = 0;
    dfs(root, s);
    return s;
}
