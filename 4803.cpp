#include <bits/stdc++.h>
using namespace std;

vector<int> adj[501];
bool check[501];

bool dfs(int p, int s) {
    bool ret = true;
    check[s] = true;
    for (auto n : adj[s]) {
        if (n == p) continue;
        if (!check[n])
            ret &= dfs(s, n);
        else
            ret = false;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int t = 1; true; t++) {
        int answer = 0;
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            check[i] = false;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (!check[i] && dfs(-1, i)) {
                answer++;
            }
        }
        if (answer == 0)
            cout << "Case " << t << ": No trees.\n";
        else if (answer == 1)
            cout << "Case " << t << ": There is one tree.\n";
        else
            cout << "Case " << t << ": A forest of " << answer << " trees.\n";
    }
}