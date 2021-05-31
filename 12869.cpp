#include <bits/stdc++.h>
using namespace std;

int dp[61][61][61];

int solve(int a, int b, int c) {
    if (a <= 0) a = 0;
    if (b <= 0) b = 0;
    if (c <= 0) c = 0;
    int &ret = dp[a][b][c];
    if (ret != -1) return ret;
    if (a == 0 && b == 0 && c == 0)
        return 0;
    else if (a == 0 && b == 0)
        ret = 1 + solve(a, b, c - 9);
    else if (b == 0 && c == 0)
        ret = 1 + solve(a - 9, b, c);
    else if (c == 0 && a == 0)
        ret = 1 + solve(a, b - 9, c);
    else if (a == 0)
        ret = 1 + min(solve(a, b - 9, c - 3), solve(a, b - 3, c - 9));
    else if (b == 0)
        ret = 1 + min(solve(a - 9, b, c - 3), solve(a - 3, b, c - 9));
    else if (c == 0)
        ret = 1 + min(solve(a - 9, b - 3, c), solve(a - 3, b - 9, c));
    else
        ret = 1 + min({solve(a - 9, b - 3, c - 1), solve(a - 9, b - 1, c - 3),
                       solve(a - 3, b - 9, c - 1), solve(a - 1, b - 9, c - 3),
                       solve(a - 3, b - 1, c - 9), solve(a - 1, b - 3, c - 9)});
    return ret;
}

int main() {
    int scv[3] = {0, 0, 0};
    int n;
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> scv[i];
    cout << solve(scv[0], scv[1], scv[2]) << "\n";
}