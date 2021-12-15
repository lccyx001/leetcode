#include "common.hh"
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return {};
  }
  vector<int> order;
  int left = 0, right = matrix[0].size() - 1, top = 0,
      bottom = matrix.size() - 1;
  while (left <= right && top <= bottom) {
    for (int column = left; column <= right; column++) {
      order.push_back(matrix[top][column]);
    }
    for (int row = top + 1; row <= bottom; row++) {
      order.push_back(matrix[row][right]);
    }
    if (left < right && top < bottom) {
      for (int column = right - 1; column > left; column--) {
        order.push_back(matrix[bottom][column]);
      }
      for (int row = bottom; row > top; row--) {
        order.push_back(matrix[row][left]);
      }
    }
    left++;
    right--;
    top++;
    bottom--;
  }
  return order;
}
