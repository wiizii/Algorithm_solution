#include <iostream>
using namespace std;

const int MAX = 100001;
const int MOD = 1000000009;

long long dp[MAX][4];

int main() {
    int t;
    cin >> t;
    dp[1][0] = dp[2][0] = dp[1][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    dp[3][0] = 3;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 4; i <= n; i++) {
            if (dp[i][0]) continue;
            dp[i][1] = ((dp[i - 1][2] % MOD) + (dp[i - 1][3] % MOD)) % MOD;
            dp[i][2] = ((dp[i - 2][1] % MOD) + (dp[i - 2][3] % MOD)) % MOD;
            dp[i][3] = ((dp[i - 3][1] % MOD) + (dp[i - 3][2] % MOD)) % MOD;
            dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % MOD;
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}