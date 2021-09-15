struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};