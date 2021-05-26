#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, w;
int dp[1001][1001];
pii e[1001];

int get_dist(pii x, pii y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int solve(int p1, int p2) {
    if (p1 == w || p2 == w) return 0;
    int &ret = dp[p1][p2];
    if (ret != -1) return ret;
    int ne = max(p1, p2) + 1;
    int tmp1, tmp2;
    if (p1 == 0)
        tmp1 = get_dist({1, 1}, e[ne]);
    else
        tmp1 = get_dist(e[p1], e[ne]);
    if (p2 == 0)
        tmp2 = get_dist({n, n}, e[ne]);
    else
        tmp2 = get_dist(e[p2], e[ne]);
    ret = min(solve(ne, p2) + tmp1, solve(p1, ne) + tmp2);
    return ret;
}

void trace(int p1, int p2) {
    if (p1 == w || p2 == w) return;
    int ne = max(p1, p2) + 1;
    int tmp1, tmp2;
    if (p1 == 0)
        tmp1 = get_dist({1, 1}, e[ne]);
    else
        tmp1 = get_dist(e[p1], e[ne]);
    if (p2 == 0)
        tmp2 = get_dist({n, n}, e[ne]);
    else
        tmp2 = get_dist(e[p2], e[ne]);
    if (solve(ne, p2) + tmp1 <= solve(p1, ne) + tmp2) {
        cout << 1 << "\n";
        trace(ne, p2);
    } else {
        cout << 2 << "\n";
        trace(p1, ne);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    for (int i = 1; i <= w; i++) cin >> e[i].first >> e[i].second;
    cout << solve(0, 0) << "\n";
    trace(0, 0);
}
