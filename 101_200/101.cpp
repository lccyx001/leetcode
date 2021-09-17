struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkSym(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    return checkSym(p->left, q->right) && checkSym(p->right, q->left) && p->val == q->val;
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return checkSym(root->left, root->right);
}
