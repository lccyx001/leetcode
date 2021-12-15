#include "common.hh"
using namespace std;

double recurive(double x, int n) {
  if (n == 0) return 1;
  if (n == 1) return x;
  return n % 2 == 0 ? recurive(x * x, n / 2) : recurive(x * x, n / 2) * x;
}

double myPow(double x, int n) {
  return n > 0 ? recurive(x, abs(n)) : 1 / recurive(x, abs(n));
}

int main() {
  cout << myPow(8.84372, -5) << endl;
  cout << pow(8.84372, -5);
}