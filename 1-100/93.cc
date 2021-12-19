#include "common.hh"
using namespace std;
bool check_valid(vector<string> vs) {
  for (auto s : vs) {
    if (s.size() > 3 && s.size() < 1) return false;
    if (s.size() > 1 && stoi(s) < 10) return false;
    if (stoi(s) > 255) return false;
  }
  return true;
}

void dfs(string s, vector<string>& ans, vector<string>& vs, int idx) {
  if (s.size() - 1 - idx > 3 * (4 - vs.size())) return;
  if (vs.size() == 4 && check_valid(vs)) {
    string p = "";
    for (auto& ip : vs) {
      p += ip + ".";
    }
    p.pop_back();
    ans.push_back(p);
    return;
  }
  for (int i = idx + 1; i < s.size(); i++) {
    if (vs.size() == 3) {
      vs.push_back(s.substr(idx, s.size() - 1 - idx));
      dfs(s, ans, vs, s.size() - 1);
      vs.pop_back();
    } else {
      vs.push_back(s.substr(idx, i - idx));
      dfs(s, ans, vs, i);
      vs.pop_back();
    }
  }
}

vector<string> restoreIpAddresses(string s) {
  vector<string> ans, vs;
  dfs(s, ans, vs, 0);
  return ans;
}

int main() {}