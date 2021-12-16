#include "common.hh"
using namespace std;

string simplifyPath(string path) {
  vector<string> s;
  int start = 0, end = 0, n = path.size();

  while (start < n) {
    if (path[start] == '/') start++;
    end = start;
    while (end < n) {
      if (path[end] == '/') break;
      end++;
    }
    string sub_path = path.substr(start, end - start);
    start = end;
    if (sub_path == "") continue;
    if (sub_path == "..") {
      if (s.size() != 0) s.pop_back();
      continue;
    } else if (sub_path != ".")
      s.push_back(sub_path);
  }
  string ans = "/";
  if (s.size() == 0) return ans;
  for (auto &zz : s) {
    ans += zz + "/";
  }
  return ans;
}

int main() {
  string a = "/../";
  simplifyPath(a);
}
