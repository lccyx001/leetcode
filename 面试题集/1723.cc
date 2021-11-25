#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findSquare(vector<vector<int>>& matrix) {
    vector<int> ans(3, 0);
    int n = matrix.size();
    if (n == 0) return {};
    if (n == 1) {
      if (matrix[0][0] == 0)
        return {0, 0, 1};
      else
        return {};
    }
    // cnt[r][c][0/1],0右侧,1下侧
    vector<vector<vector<int>>> cnt(n, vector<vector<int>>(n, vector<int>(2)));
    for (int r = n - 1; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        if (matrix[r][c] == 1)
          cnt[r][c][0] = cnt[r][c][1] = 0;
        else {
          //统计cnt[r][c][0/1]
          if (r < n - 1)
            cnt[r][c][1] = cnt[r + 1][c][1] + 1;
          else
            cnt[r][c][1] = 1;

          if (c < n - 1)
            cnt[r][c][0] = cnt[r][c + 1][0] + 1;
          else
            cnt[r][c][0] = 1;
          //更新当前最大子方阵
          int len = min(cnt[r][c][0], cnt[r][c][1]);  //最大的可能的边长
          while (len >= ans[2]) {  //要答案r,c最小，所以带等号
            if (cnt[r + len - 1][c][0] >= len &&
                cnt[r][c + len - 1][1] >= len) {
              //可以构成长为len的方阵
              ans = {r, c, len};
              break;
            }
            len--;
          }
        }
      }
    }
    return ans;
  }
};

// 作者：SY_rabbit
// 链接：https://leetcode-cn.com/problems/max-black-square-lcci/solution/c-dong-tai-gui-hua-by-tmoonli/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。