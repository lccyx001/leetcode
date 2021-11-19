#include <iostream>
#include <vector>
using namespace std;
int waysToChange(int n) {
  vector<int> f(n + 1, 0);
  vector<int> coins({1, 5, 10, 25});
  int mod = 1000000007;
  f[0] = 1;
  for (int c = 0; c < 4; ++c) {
    int coin = coins[c];
    for (int i = coin; i <= n; ++i) {
      f[i] = (f[i] + f[i - coin]) % mod;
    }
  }
  return f[n];
}