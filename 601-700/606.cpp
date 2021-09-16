
#include <string>
#include <iostream>
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

void wfs(TreeNode *root)
{
    if (!root)
        return;
    string s = "";

    s += to_string(root->val);
    if (root->left || (!root->left && root->right))
    {
        s += "(";
        wfs(root->left);
        s += ")";
    }
    if (root->right)
    {
        s += "(";
        wfs(root->right);
        s += ")";
    }
};

string tree2str(TreeNode *root)
{
}

int main()
{
    cout << (char)1 << endl;
}