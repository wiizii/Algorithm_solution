#include <algorithm>
#include <cstring>
#include <iostream>
#define ll long long
using namespace std;

const int MOD = 1000000007;
ll dp[5001];

ll solve(int n) {
    if (n == 0) return 1;
    if (dp[n] >= 0) return dp[n];
    dp[n] = 0;
    for (int i = 2; i <= n; i += 2) {
        dp[n] += solve(i - 2) * solve(n - i);
        dp[n] %= MOD;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--) {
        int n;
        cin >> n;
        if (n % 1)
            cout << "0\n";
        else
            cout << solve(n) << "\n";
    }
}