#include <iostream>
using namespace std;
const int MAX = 1000000;
const int mod = 1000000009;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    long long dp[MAX + 1] = {0, 1, 2, 4};
    for (int i = 4; i <= MAX; i++)
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % mod;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}