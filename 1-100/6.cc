#include <iostream>
#include <string>
#include <vector>
using namespace std;
string convert(string s, int numRows) {
  vector<string> res(numRows, "");
  int n = s.size(), flag = -1, j = 0;
  if (numRows < 2) return s;
  for (int i = 0; i < n; i++) {
    res[j] += s[i];
    if (j == 0 || j == numRows - 1) flag = -flag;
    j += flag;
  }
  string ans;
  for (auto &si : res) {
    cout << si << endl;
    ans += si;
  }
  return ans;
}

int main() {
  string s = "PAYPALISHIRING";
  convert(s, 3);
}
