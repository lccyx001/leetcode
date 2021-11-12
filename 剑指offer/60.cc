#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
vector<double> dicesProbability(int n) {
  vector<vector<int>> dp(n + 1, vector<int>(n * 6 + 1, 0));
  for (int i = 1; i <= 6; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= i * 6; j++) {
      for (int k = 1; k <= 6; k++) {
        if (j > k) dp[i][j] += dp[i - 1][j - k];
      }
    }
  }
  
  vector<double> ans;
  int sum = pow(6, n);
  for (int i = n; i <= n * 6; i++) {
    ans.push_back(dp[n][i] * 1.0 / sum);
  }
  return ans;
}

int main() {
  vector<double> a = dicesProbability(1);
  // cout << 1.0 / 36;
}