#include "common.hh"
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals,
                           vector<int>& newInterval) {
  intervals.push_back(newInterval);
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> merged;
  int NL = newInterval[0], NR = newInterval[1];
  for (int i = 0; i < intervals.size(); i++) {
    int L = intervals[i][0], R = intervals[i][1];
    if (!merged.size() || L > merged.back()[1])
      merged.push_back(intervals[i]);
    else
      merged.back()[1] = R > merged.back()[1] ? R : merged.back()[1];
  }
  return merged;
}