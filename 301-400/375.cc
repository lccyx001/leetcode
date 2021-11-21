
#include <vector>
using namespace std;

class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> f(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 1; i--) {
      for (int j = i + 1; j <= n; j++) {
        f[i][j] = j + f[i][j - 1];
        for (int k = i; k < j; k++) {
          f[i][j] = min(f[i][j], k + max(f[i][k - 1], f[k + 1][j]));
        }
      }
    }
    return f[1][n];
  }
};
