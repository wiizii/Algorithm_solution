#include <bits/stdc++.h>
using namespace std;

int parent[500001];
int n, m;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    int u, v;
    for (int i = 0; i < n; i++) parent[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (find(u) == find(v)) {
            ans = i;
            break;
        } else
            merge(u, v);
    }
    cout << ans << "\n";
}