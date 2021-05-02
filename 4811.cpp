#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[61][31];

ll solve(int w, int h) {
    if (w == 0 && h == 0) return 1;
    ll &ret = dp[w][h];
    if (ret) return ret;
    if (w > 0) ret += solve(w - 1, h + 1);
    if (h > 0) ret += solve(w, h - 1);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        memset(dp, 0, sizeof(dp));
        int W = 0, H = 0;
        cin >> W;
        if (W == 0) break;
        cout << solve(W, H) << "\n";
    }
}
