#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int arr[20][20];
int n;
int dp[20][1 << 20];

int solve(int x, int visited) {
    if (visited == (1 << n) - 1) return 0;
    int &ret = dp[x][visited];
    if (ret != -1) return ret;
    ret = INF;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        ret = min(ret, solve(x + 1, visited | (1 << i)) + arr[x][i]);
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0);
}