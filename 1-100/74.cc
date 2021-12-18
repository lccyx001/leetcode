#include "common.hh"
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (target < matrix[0][0]) return false;
  int m = matrix.size(), n = matrix[0].size();
  if (target > matrix[m - 1][n - 1]) return false;

  for (int i = 0; i < m; i++) {
    if (matrix[i][n - 1] < target) continue;
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == target) return true;
      if (matrix[i][j] > target) return false;
    }
  }
  return false;
}