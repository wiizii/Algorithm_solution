#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> adj[11];
int p[11];
bool check[11];
int n;

int bfs(vector<int> &v) {
    int ret = 0;
    memset(check, 0, sizeof(check));
    queue<int> q;
    q.push(v[0]);
    check[v[0]] = true;
    ret += p[v[0]];
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            bool flag = false;
            for (int k : v)
                if (k == y) flag = true;
            if (!check[y] && flag) {
                check[y] = true;
                ret += p[y];
                q.push(y);
            }
        }
    }
    for (int i : v)
        if (!check[i]) return -1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int u = 1; u <= n; u++) {
        int m;
        cin >> m;
        while (m--) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int ans = INF;

    for (int i = 1; i < (1 << n) - 1; i++) {
        vector<int> r, b;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j))
                r.push_back(j + 1);
            else
                b.push_back(j + 1);
        }
        int rcnt = bfs(r);
        int bcnt = bfs(b);
        if (rcnt == -1 || bcnt == -1) continue;
        ans = min(ans, abs(rcnt - bcnt));
    }

    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}