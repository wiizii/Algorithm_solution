#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 100001;
int n, m, k;
vector<int> adj[MAX];
int check[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int a;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (i == k - 1) {
            a = u;
            continue;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(a);
    check[a] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            if (!check[next]) {
                check[next] = true;
                q.push(next);
            }
        }
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!check[i]) cnt++;
    }
    cout << cnt * (n - cnt) << "\n";
}