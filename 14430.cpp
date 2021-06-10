#include <bits/stdc++.h>
using namespace std;

int arr[301][301];
int dp[301][301];
int n, m;

int solve(int x, int y) {
    int &ret = dp[x][y];
    if (ret != -1) return ret;
    ret = arr[x][y];
    if (x == 0 && y == 0) return ret;
    if (x < 0 || y < 0) return 0;
    ret += max(solve(x - 1, y), solve(x, y - 1));
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    cout << solve(n - 1, m - 1) << "\n";
}