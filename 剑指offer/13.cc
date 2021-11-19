#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool checkvalid(int x, int y, int k, int m, int n) {
  if (x > m - 1 || y > n - 1) return false;
  int x1 = x / 10, x2 = x % 10;
  int y1 = y / 10, y2 = y % 10;
  return x1 + x2 + y1 + y2 <= k;
}

int movingCount(int m, int n, int k) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!checkvalid(i, j, k, m, n)) break;
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int m = 3, n = 2, k = 17;
  cout << movingCount(m, n, k);
}