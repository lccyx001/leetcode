#include "common.hh"
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  unordered_map<string, vector<string>> mp;
  for (string& str : strs) {
    string key = str;
    sort(key.begin(), key.end());
    mp[key].emplace_back(str);
  }
  vector<vector<string>> ans;
  for (auto it = mp.begin(); it != mp.end(); ++it) {
    ans.emplace_back(it->second);
  }
  return ans;
}
int main() {
  vector<string> a({"eat", "tea", "tan", "ate", "nat", "bat", "ac", "bd", "aac",
                    "bbd", "aacc", "aacc", "bbdd", "acc", "bdd"});
  sort(a.begin(), a.end());
  for (auto& ai : a) {
    cout << ai << "  ";
  }
}