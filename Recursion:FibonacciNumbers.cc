#include <iostream>
#include <cstring>

using namespace std;

int memo[35];

int fibonacci(int n) {
    if (n < 2)
        return n;
    if (memo[n] != -1)
        return memo[n];
    return memo[n] = fibonacci(n-2) + fibonacci(n-1);
}
int main() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);
    cout << fibonacci(n);
    return 0;
}
