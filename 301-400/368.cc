#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
vector<int> largestDivisibleSubset(vector<int>& nums) {
  int len = nums.size();
  sort(nums.begin(), nums.end());

  // 第 1 步：动态规划找出最大子集的个数、最大子集中的最大整数
  vector<int> dp(len, 1);
  int maxSize = 1;
  int maxVal = dp[0];
  for (int i = 1; i < len; i++) {
    for (int j = 0; j < i; j++) {
      // 题目中说「没有重复元素」很重要
      if (nums[i] % nums[j] == 0) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }

    if (dp[i] > maxSize) {
      maxSize = dp[i];
      maxVal = nums[i];
    }
  }

  // 第 2 步：倒推获得最大子集
  vector<int> res;
  if (maxSize == 1) {
    res.push_back(nums[0]);
    return res;
  }

  for (int i = len - 1; i >= 0 && maxSize > 0; i--) {
    if (dp[i] == maxSize && maxVal % nums[i] == 0) {
      res.push_back(nums[i]);
      maxVal = nums[i];
      maxSize--;
    }
  }
  return res;
}

int main() {
  vector<int> a, b;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  //   a.push_back(8);
  //   a.push_back(9);
  b = largestDivisibleSubset(a);
  //   for (auto& x : b) {
  //     cout << x << endl;
  //   }
  //   cout << endl;
}