#include <cstdio>
#define ll long long

int main() {
    int map[33][33] = {
        0,
    };
    ll dp[3][33][33] = {
        0,
    };
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &map[i][j]);
    dp[0][1][2] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 3; j <= n; j++) {
            if (!map[i][j]) {
                dp[0][i][j] = dp[0][i][j - 1] + dp[1][i][j - 1];
                if (map[i - 1][j] != 1 && map[i][j - 1] != 1)
                    dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] +
                                  dp[2][i - 1][j - 1];
                dp[2][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
            }
        }
    }
    printf("%lld\n", dp[0][n][n] + dp[1][n][n] + dp[2][n][n]);
    return 0;
}