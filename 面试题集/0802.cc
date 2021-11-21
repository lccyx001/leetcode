#include <vector>
using namespace std;
class Solution {
 public:
  bool find = false;
  int dir[2][2] = {{0, 1}, {1, 0}};
  vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[rows - 1][cols - 1]) return {};
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> path;
    visited[0][0] = true;
    path.push_back({0, 0});
    dfs(obstacleGrid, visited, path, rows, cols, 0, 0);
    if (find) return path;
    return {};
  }
  void dfs(const vector<vector<int>>& grids, vector<vector<bool>>& visited,
           vector<vector<int>>& path, int rows, int cols, int curRow,
           int curCol) {
    if (find) return;
    if (curRow == rows - 1 && curCol == cols - 1) {
      find = true;
      return;
    }
    for (int d = 0; d < 2 && !find; ++d) {
      int newRow = curRow + dir[d][0];
      int newCol = curCol + dir[d][1];
      if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
        if (!visited[newRow][newCol] && !grids[newRow][newCol]) {
          visited[newRow][newCol] = true;
          path.push_back({newRow, newCol});
          dfs(grids, visited, path, rows, cols, newRow, newCol);
          if (!find) {
            // 如果前后左右都能走，那么回溯的时候visited要置成false
            // visited[newRow][newCol] = false;
            path.pop_back();
          }
        }
      }
    }
  }
};
