#include <bits/stdc++.h>
using namespace std;

int arr[15];

int dp[100][1 << 15];
int n, k;

int solve(int x, int visited) {
    if (visited == (1 << n) - 1) return 0;
    int &ret = dp[x][visited];
    if (ret != -1) return ret;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) continue;
        ret = (solve(x + 1, visited | (1 << i)) + arr[i]);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    cout << solve(0, 0);
}