#include "common.hh"
using namespace std;
vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  int left = 0, right = n - 1, top = 0, bottom = n - 1, cnt = 1;

  while (left <= right && top <= bottom) {
    for (int i = left; i <= right; i++) {
      matrix[top][i] = cnt++;
    }
    for (int i = top + 1; i <= bottom; i++) {
      matrix[i][right] = cnt++;
    }
    if (left < right && top < bottom) {
      for (int i = right - 1; i >= left; i--) {
        matrix[bottom][i] = cnt++;
      }
      for (int i = bottom - 1; i > top; i--) {
        matrix[i][left] = cnt++;
      }
    }
    left++;
    right--;
    top++;
    bottom--;
  }
  return matrix;
}