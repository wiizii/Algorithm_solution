#include <bits/stdc++.h>
using namespace std;

int arr[2][100001];
int dp[2][100001];

int solve(int n, int m) {
    if (m < 0) return 0;
    if (m == 0) return arr[n][m];
    if (dp[n][m] != -1) return dp[n][m];
    if (n == 0)
        return dp[n][m] = arr[n][m] + max(solve(1, m - 1), solve(1, m - 2));
    else
        return dp[n][m] = arr[n][m] + max(solve(0, m - 1), solve(0, m - 2));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++) cin >> arr[0][i];
        for (int i = 0; i < n; i++) cin >> arr[1][i];

        cout << max(solve(0, n - 1), solve(1, n - 1)) << "\n";
    }
}