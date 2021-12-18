#include "common.hh"
using namespace std;

bool check_valid(int m, int n, vector<int> pos) {
  if (pos[0] < 0 || pos[0] >= m || pos[1] < 0 || pos[1] >= n) return false;
  return true;
}

bool search_rec(vector<vector<char>>& board, string word, vector<int> pos,
                vector<vector<int>> used, int m, int n, int idx) {
  if (used[pos[0]][pos[1]]) return false;
  if (board[pos[0]][pos[1]] != word[idx]) return false;
  used[pos[0]][pos[1]] = 1;
  if (word.size() == idx + 1) return true;
  if (check_valid(m, n, {pos[0] + 1, pos[1]}) &&
      search_rec(board, word, {pos[0] + 1, pos[1]}, used, m, n, idx + 1))
    return true;
  if (check_valid(m, n, {pos[0] - 1, pos[1]}) &&
      search_rec(board, word, {pos[0] - 1, pos[1]}, used, m, n, idx + 1))
    return true;
  if (check_valid(m, n, {pos[0], pos[1] + 1}) &&
      search_rec(board, word, {pos[0], pos[1] + 1}, used, m, n, idx + 1))
    return true;
  if (check_valid(m, n, {pos[0], pos[1] - 1}) &&
      search_rec(board, word, {pos[0], pos[1] - 1}, used, m, n, idx + 1))
    return true;
  used[pos[0]][pos[1]] = 0;
  return false;
}

bool exist(vector<vector<char>>& board, string word) {
  int m = board.size(), n = board[0].size();
  vector<vector<int>> used(m, vector<int>(n, 0));
  bool flag = false;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      flag = search_rec(board, word, {i, j}, used, m, n, 0);
      if (flag) return flag;
    }
  }
  return false;
}

// 两个答案逻辑一样
class Solution {
 public:
  bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i,
             int j, string& s, int k) {
    if (board[i][j] != s[k]) {
      return false;
    } else if (k == s.length() - 1) {
      return true;
    }
    visited[i][j] = true;
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool result = false;
    for (const auto& dir : directions) {
      int newi = i + dir.first, newj = j + dir.second;
      if (newi >= 0 && newi < board.size() && newj >= 0 &&
          newj < board[0].size()) {
        if (!visited[newi][newj]) {
          bool flag = check(board, visited, newi, newj, s, k + 1);
          if (flag) {
            result = true;
            break;
          }
        }
      }
    }
    visited[i][j] = false;
    return result;
  }

  bool exist(vector<vector<char>>& board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        bool flag = check(board, visited, i, j, word, 0);
        if (flag) {
          return true;
        }
      }
    }
    return false;
  }
};
