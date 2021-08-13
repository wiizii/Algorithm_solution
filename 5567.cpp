#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> adj[501];
bool check[501];
int n, m;

int bfs(int start) {
    int ret = 0;
    queue<pii> q;
    q.push({start, 0});
    check[start] = true;
    while (!q.empty()) {
        auto [x, cnt] = q.front();
        q.pop();
        cnt++;
        for (auto next : adj[x]) {
            if (!check[next] && cnt <= 2) {
                check[next] = true;
                ret++;
                q.push({next, cnt});
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << bfs(1) << "\n";
}