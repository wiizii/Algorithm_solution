#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 20010;
const int INF = 0x3f3f3f3f;
int n, m;
vector<int> adj[MAX];
bool check[MAX];
int w = 1, e, r = 1;

void bfs() {
    queue<pii> q;
    q.push({1, 0});
    check[1] = true;
    while (!q.empty()) {
        auto [cur, d] = q.front();
        q.pop();
        for (auto &next : adj[cur]) {
            int nd = d + 1;
            if (check[next]) continue;
            if (e < nd) {
                w = next;
                e = nd;
                r = 1;
            } else if (e == nd) {
                w = min(w, next);
                r++;
            }
            check[next] = true;
            q.push({next, nd});
        }
    }
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

    bfs();

    cout << w << " " << e << " " << r;
}