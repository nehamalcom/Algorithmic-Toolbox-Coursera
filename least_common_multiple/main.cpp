#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

long long gcd_fast(int a, int b)
{
    long long temp;
    while(b!=0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    //cout<<"gcd is"<<a;
    return a;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b)
{
    long long gcd;
    long long lcm;
    gcd = gcd_fast(a, b);
    lcm = a/gcd;
    lcm = lcm*b;
    return lcm;

}

void test_solution() {

    for (int n = 0; n < 20; ++n)
        assert(lcm_fast(n+183,n+100) == lcm_naive(n+183,n+100));
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  //test_solution();
  std::cout << lcm_fast(a, b) << '\n';
  return 0;
}
