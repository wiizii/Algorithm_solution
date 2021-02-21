#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int arr[101];
int dp[101][101];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][1] + arr[i], arr[i]);
    }
    for (int j = 2; j <= m; j++) {
        for (int i = 3; i <= n; i++) {
            dp[i][j] = max(dp[i - 1][j] + arr[i], dp[i - 2][j - 1] + arr[i]);
        }
    }
    int ans = -32768 * 101;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][m]);
    }
    cout << ans << "\n";
}