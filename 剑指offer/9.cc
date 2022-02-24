#include "common.hh"
using namespace std;
class CQueue {
 public:
  CQueue() {
    while (!s1.empty()) {
      s1.pop();
    }
    while (!s2.empty()) {
      s2.pop();
    }
  }

  void appendTail(int value) { s1.push(value); }

  int deleteHead() {
    if (s2.size() > 0) {
      int ans = s2.top();
      s2.pop();
      return ans;
    }
    while (s1.size() > 0) {
      s2.push(s1.top());
      s1.pop();
    }
    if (s2.empty()) return -1;
    int ans = s2.top();
    s2.pop();
    return ans;
  }

 private:
  stack<int> s1, s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */