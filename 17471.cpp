#include <bits/stdc++.h>
using namespace std;

vector<int> adj[11];
int p[11];
bool check[11];
int n;
int ans = 0x3f3f3f3f;
vector<int> r, b;

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
            for (int k : v) {
                if (k == y) flag = true;
            }
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

void solve(int cnt) {
    if (cnt == n + 1) {
        if (r.empty() || b.empty()) return;
        int rcnt = bfs(r);
        int bcnt = bfs(b);
        if (rcnt == -1 || bcnt == -1) return;
        ans = min(ans, abs(rcnt - bcnt));
        return;
    }
    r.push_back(cnt);
    solve(cnt + 1);
    r.pop_back();
    b.push_back(cnt);
    solve(cnt + 1);
    b.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }
    solve(1);
    if (ans == 0x3f3f3f3f)
        cout << -1 << "\n";
    else
        cout << ans << "\n";
}