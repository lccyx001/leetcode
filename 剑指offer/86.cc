#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPal(const string& s) {
  int n = s.size();
  int i = 0, j = n - 1;
  while (i < j) {
    if (s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}

void dfs(string& s, int start, vector<string>& buf,
         vector<vector<string>>& ans) {
  if (start == s.size()) {
    ans.push_back(buf);
    return;
  }
  for (int i = start; i < s.size(); i++) {
    if (isPal(s.substr(start, i - start + 1))) {
      buf.push_back(s.substr(start, i - start + 1));
      dfs(s, i + 1, buf, ans);
      buf.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> ans;
  vector<string> buf;
  dfs(s, 0, buf, ans);
  return ans;
}

int main() {
  string s = "abcddcba";
  vector<vector<string>> ans = partition(s);
  for (auto& a : ans) {
    for (auto& al : a) {
      cout << al << ",";
    }
    cout << endl;
  }
}