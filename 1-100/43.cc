#include "common.hh"
using namespace std;

string multiply(string num1, string num2) {
  vector<int> A, B;
  int n = num1.size(), m = num2.size();
  for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0');  //反向存贮
  for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');
  vector<int> C(n + m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) C[i + j] += A[i] * B[j];
  int t = 0;  //存贮进位
  for (int i = 0; i < C.size(); i++) {
    t += C[i];
    C[i] = t % 10;
    t /= 10;
  }
  int k = C.size() - 1;
  while (k > 0 && !C[k]) k--;  //去除前导0
  string res;
  while (k >= 0) res += C[k--] + '0';  //反转
  return res;
}