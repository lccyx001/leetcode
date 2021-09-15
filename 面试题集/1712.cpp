#include <string>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *ans = new TreeNode(0), *cur = ans;
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        dfs(node->left);
        node->left = nullptr;  // 先把节点处理干净，再链接
        cur->right = node;
        cur = node;
        dfs(node->right);
    };

public:
    TreeNode *convertBiNode(TreeNode *root)
    {
        dfs(root);
        return ans->right;
    }
};

int main(){

}