#include <iostream>
#include <string>
#include <vector>
using namespace std;
int translateNum(int num) {
  string m = to_string(num);
  int n = m.size();
  vector<int> dp(n + 1, 0);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (10 <= stoi(m.substr(i - 2, 2)) && stoi(m.substr(i - 2, 2)) <= 25)
      dp[i] = dp[i - 1] + dp[i - 2];
    else
      dp[i] = dp[i - 1];
  }
  return dp[n];
}

int main() {
  bool a = "10" <= "25";
  cout << a;
}