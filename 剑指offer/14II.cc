#include <vector>
using namespace std;

int cuttingRope(int n) {
  //已知n >= 2,当2 <= n <= 4时，结果如下
  if (n == 2) return 1;
  if (n == 3) return 2;
  if (n == 4) return 4;
  //当n > 4时，要剪出来尽可能多长度为3的段,当n <= 4的时候，不再剪段
  long res = 1;  //一定要用long类型，否则当n较大时，使用int类型的话res会越界
  int mod = (int)1e9 + 7;
  while (n > 4) {
    res = res * 3 % mod;
    n -= 3;
  }
  return (int)(res * n % mod);  //这里是乘上最后小于等于4的段
}