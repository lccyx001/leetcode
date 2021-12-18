#include "common.hh"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  vector<vector<int>> pos;
  int m = matrix.size(), n = matrix[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0) pos.push_back({i, j});
    }
  }

  for (auto& pv : pos) {
    for (int i = 0; i < m; i++) {
      matrix[i][pv[1]] = 0;
    }
    for (int i = 0; i < n; i++) {
      matrix[pv[0]][i] = 0;
    }
  }
}