/* 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。

注意：本题相对原题稍作改动

示例：

输入： 1->2->3->4->5 和 k = 2
输出： 4
说明：

给定的 k 保证是有效的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

int kthToLast(struct ListNode *head, int k)
{
    struct ListNode *tail = head;
    struct ListNode *kth = head;
    while (k > 1)
    {
        tail = tail->next;
        k--;
    }

    while (tail)
    {
        if (tail->next == NULL)
            break;
        tail = tail->next;
        kth = kth->next;
    }
    return kth->val;
}

int main()
{
    struct ListNode *a = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *b = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *c = (struct ListNode *)malloc(sizeof(struct ListNode));
    a->val = 1;
    a->next = b;
    b->val = 2;
    printf("%d,\n", a->next->val);
    b->next = c;
    c->val = 3;
    c->next = NULL;
    int d = kthToLast(a, 1);
    printf("%d", d);
}