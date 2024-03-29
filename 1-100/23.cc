#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {}
  ListNode* mergetwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    ListNode head, cur;
    head = cur;
    while (l1 && l2) {
      if (l1->val <= l2->val)
        cur.next = l1;
      else
        cur.next = l2;
    }
    return head.next;
    // head->next = cur;
  }
};