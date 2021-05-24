#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
int cost[1001][1001];
int n, m;

int solve(int prev, int cur) {
    int tmp = 0;
    for (auto next : adj[cur]) {
        if (next == prev) continue;
        tmp += solve(cur, next);
    }
    if (cur == 1) return tmp;
    if (tmp == 0) return cost[prev][cur];
    return min(tmp, cost[prev][cur]);
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
            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u][v] = w;
            cost[v][u] = w;
        }
        cout << solve(-1, 1) << "\n";
    }
}
