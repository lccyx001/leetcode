#include "common.hh"
using namespace std;

class Solution {
 public:
  void init(unordered_map<char, int>& um) {
    if (um.size() < 1) {
      um.insert(pair<char, int>('1', 0));
      um.insert(pair<char, int>('2', 0));
      um.insert(pair<char, int>('3', 0));
      um.insert(pair<char, int>('4', 0));
      um.insert(pair<char, int>('5', 0));
      um.insert(pair<char, int>('6', 0));
      um.insert(pair<char, int>('7', 0));
      um.insert(pair<char, int>('8', 0));
      um.insert(pair<char, int>('9', 0));
    } else {
      for (auto& it : um) {
        it.second = 0;
      }
    }
  }
  bool checkline(vector<vector<char>>& board, unordered_map<char, int>& um) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;
        if (um[board[i][j]] > 0) return false;
        um[board[i][j]]++;
      }
      init(um);
    }
    return true;
  }
  bool checkrow(vector<vector<char>>& board, unordered_map<char, int>& um) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[j][i] == '.') continue;
        if (um[board[j][i]] > 0) return false;
        //   if(i==0)
        //   cout<<j<<" "<<i<<" "<<um[board[j][i]]<<endl;
        um[board[j][i]]++;
      }
      init(um);
    }
    return true;
  }

  bool checkunit(vector<vector<char>>& board, unordered_map<char, int>& um) {
    int i = 0, j = 0;
    while (i < 3 && j < 3) {
      for (int offset_i = 0; offset_i < 3; offset_i++) {
        for (int offset_j = 0; offset_j < 3; offset_j++) {
          if (board[i * 3 + offset_i][j * 3 + offset_j] == '.') continue;
          if (um[board[i * 3 + offset_i][j * 3 + offset_j]] > 0) return false;
          um[board[i * 3 + offset_i][j * 3 + offset_j]]++;
        }
      }
      init(um);
      if (i >= 3) break;
      j++;
      if (j >= 3) {
        j = 0;
        i++;
      }
    }
    return true;
  }
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_map<char, int> um;
    // init(um);
    // check line
    if (!checkline(board, um)) return false;
    // cout << "check line success" << endl;
    // check row
    // init(um);
    if (!checkrow(board, um)) return false;
    // cout << "check row success" << endl;
    // check unit
    // init(um);
    if (!checkunit(board, um)) return false;
    // cout << "check unit success" << endl;
    return true;
  }
};