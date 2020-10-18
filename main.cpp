#include <iostream>
#include <vector>

using namespace std;


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long fibonacci_huge_fast(long long n, long long m) {
    vector<long long int> fibonacci_sequence(n+1,0);
    /*for(int i=0;i<n+1;i++)
            cout<<fibonacci_sequence[i];*/
    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;
    for (int i=2;i<n+1;i++)
    {
        fibonacci_sequence[i] = (fibonacci_sequence[i-1] + fibonacci_sequence[i-2])%m;
    }
    return fibonacci_sequence[n];
}

void test_solution() {
    //assert(fibonacci_fast(3) == 2);
    //assert(fibonacci_fast(10) == 55);
    for (int n = 1999; n < 10000; ++n)
        assert(fibonacci_huge_fast(n,1005) == get_fibonacci_huge_naive(n,1005));
}

int main() {
    long long n, m;
    //std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';

    //std::cout << fibonacci_naive(n) << '\n';
    test_solution();
    //std::cout << fibonacci_huge_fast(n, m) << '\n';
    return 0;
}
