#include "common.hh"

using namespace std;

class MinStack {
 private:
  stack<int> s1, s2;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    if (s2.size() < 1 || x < s2.top()) s2.push(x);
    s1.push(x);
  }

  void pop() {
    int x = s1.top();
    if (x == s2.top()) s2.pop();
    s1.pop();
  }

  int top() { return s1.top(); }

  int min() { return s2.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */