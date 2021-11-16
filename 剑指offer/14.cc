#include <math.h>
# include<vector>
#include <iostream>
using namespace std;

int cuttingRope(int n) {
  if (n < 4) {
    return n - 1;
  }
  vector<int> products(n + 1, 0);
  products[1] = 1;
  products[2] = 2;
  products[3] = 3;
  for (int i = 4; i <= n; ++i) {
    int maxVal = 0;
    for (int j = 1; j <= i / 2; ++j) {
      maxVal = max(maxVal, products[j] * products[i - j]);
    }
    products[i] = maxVal;
  }
  return products[n];
}

int main() { cout << 10 * 1.0 / 3; }