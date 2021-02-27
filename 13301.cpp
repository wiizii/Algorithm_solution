#include <iostream>
#define ll long long
using namespace std;

ll dp[81] = {
    0,
    1,
    1,
};

ll fibo(int n) {
    if (dp[n] || n == 0) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n;
    cin >> n;
    ll ans = 2 * (fibo(n) + (fibo(n - 1) + fibo(n)));
    cout << ans << "\n";
}