#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;
const int MOD = 1000000000;

int dp[10][MAX][1 << 10];
int n;

int solve(int s, int l, int mask) {
    if (l == n) {
        if (mask == (1 << 10) - 1) {
            return 1;
        } else
            return 0;
    }
    int &ret = dp[s][l][mask];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    if (s - 1 >= 0) {
        ret += solve(s - 1, l + 1, mask | (1 << (s - 1)));
    }
    if (s + 1 < 10) {
        ret += solve(s + 1, l + 1, mask | 1 << (s + 1));
    }
    ret %= MOD;
    return ret;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i < 10; i++) {
        memset(dp, -1, sizeof(dp));
        ans += solve(i, 1, 1 << i);
        ans %= MOD;
    }
    cout << ans << endl;
}