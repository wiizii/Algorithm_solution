#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int n, m;
vector<int> adj[10001];
vector<pii> ans;
bool check[10001];

bool cmp(const pii &a, const pii &b) {
    if (a.second > b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    else
        return false;
}

int bfs(int _x) {
    int ret = 0;
    memset(check, 0, sizeof(check));
    queue<int> q;
    q.push(_x);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int next : adj[x]) {
            if (!check[next]) {
                check[next] = true;
                ret++;
                q.push(next);
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
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        int size = bfs(i);
        ans.push_back({i, size});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].first << " ";
    for (int i = 1; i < ans.size(); i++)
        if (ans[i].second == ans[0].second) cout << ans[i].first << " ";
}