#include "common.hh"
using namespace std;
class Solution {
 public:
  int minFallingPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, 20000));
    for (int i = 0; i < n; i++) dp[0][i] = grid[0][i];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          if (j != k) dp[i][j] = min(dp[i - 1][k] + grid[i][j], dp[i][j]);
        }
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};