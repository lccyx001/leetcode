#include "common.hh"
using namespace std;

vector<int> diStringMatch(string s) {
  int n = s.size();
  vector<int> ans(n + 1, 0);
  for (int i = 0; i < n + 1; i++) {
    ans[i] = i;
  }
  bool flag = true;
  while (flag) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'I' && ans[i] > ans[i + 1] ||
          s[i] == 'D' && ans[i] < ans[i + 1]) {
        swap(ans[i], ans[i + 1]);
        cnt++;
      }
    }
    if (cnt)
      flag = true;
    else
      flag = false;
  }
  return ans;
}
// 巧妙解法
class Solution {
 public:
  vector<int> diStringMatch(string s) {
    /**********************************************************
     * 问题可以转化为生成相邻为升序或降序的字符串， 那么只要每一次从自然数
     * 组的头(升序)或尾(降序)取数字就可以了
     ***********************************************************/

    unsigned int l = 0;
    unsigned int r = s.size();

    vector<int> result;

    for (auto ch : s) {
      if (ch == 'I') {
        result.push_back(l++);
      } else {
        result.push_back(r--);
      }
    }
    result.push_back(l);

    return result;
  }
};