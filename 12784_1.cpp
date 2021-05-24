#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<pii> adj[1001];
int n, m;

int solve(int prev, int cur) {
    int ret = 0;
    if (adj[cur].size() == 1 && adj[cur][0].first == prev) return 0x3f3f3f3f;
    for (auto i : adj[cur]) {
        auto [next, cost] = i;
        if (prev == next) continue;
        ret += min(solve(cur, next), cost);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        cout << solve(-1, 1) << "\n";
    }
}
