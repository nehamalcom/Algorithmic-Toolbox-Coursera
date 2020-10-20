#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_fast(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    
    return a;
}

void test_solution() {

    for (int n = 0; n < 20; ++n)
        assert(gcd_fast(n+183,n+100) == gcd_naive(n+183,n+100));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  //test_solution();
  std::cout << gcd_fast(a, b) << '\n';
  return 0;
}
