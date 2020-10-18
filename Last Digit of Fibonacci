#include <iostream>
#include <vector>

using namespace std;

int get_fibonacci_last_digit_naive(int n) {
    vector<int> fibonacci_sequence(n+1,0);
    /*for(int i=0;i<n+1;i++)
            cout<<fibonacci_sequence[i];*/
    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;
    for (int i=2;i<n+1;i++)
    {
        fibonacci_sequence[i] = (fibonacci_sequence[i-1] + fibonacci_sequence[i-2])%10;
    }
    return fibonacci_sequence[n];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
